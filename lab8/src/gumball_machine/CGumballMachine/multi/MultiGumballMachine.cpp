#include "pch.h"

#include "MultiGumballMachine.h"

#include "../../state/CState/NoQuarterState.h"
#include "../../state/CState/multi/MultiSoldState.h"
#include "../../state/CState/multi/MultiHasQuarterState.h"
#include "../../state/CState/multi/MultiSoldOutState.h"

#include "../../Description.h"
#include "../../state/CState/msg/Sold.h"

namespace gumball_machine
{

namespace multi
{

constexpr auto INVALID_MAX_QUARTERS_IN_HOLD_MSG = "Failed to create gumball machine. Bad maxQuartersInHold argument's value = %1%";

GumballMachine::GumballMachine(size_t maxQuartersInHold, REchoStream echoOutput)
	: m_maxQuartersInHoldCount(maxQuartersInHold)
	, m_echoOutput(echoOutput)
	, m_gumCount(0)
	, m_quarterCount(0)
	, m_currentState(new state::multi::SoldOutState(*this, m_echoOutput))
{
	if (m_maxQuartersInHoldCount == 0)
	{
		throw std::invalid_argument((boost::format(INVALID_MAX_QUARTERS_IN_HOLD_MSG) % maxQuartersInHold).str());
	}
}

GumballMachine::GumballMachine(size_t maxQuartersInHold, size_t onInitBallsCount, REchoStream echoOutput)
	: m_maxQuartersInHoldCount(maxQuartersInHold)
	, m_echoOutput(echoOutput)
	, m_gumCount(onInitBallsCount)
	, m_quarterCount(0)
	, m_currentState(new state::multi::SoldOutState(*this, m_echoOutput))
{
	if (m_maxQuartersInHoldCount == 0)
	{
		throw std::invalid_argument((boost::format(INVALID_MAX_QUARTERS_IN_HOLD_MSG) % maxQuartersInHold).str());
	}

	(m_gumCount > 0)
		? SetNoQuarterState()
		: SetSoldOutState();
}

void GumballMachine::InsertQuarter()
{
	m_currentState->InsertQuarter();
	if (m_quarterCount < m_maxQuartersInHoldCount)
	{
		++m_quarterCount;
	}
}

void GumballMachine::EjectQuarter()
{
	m_currentState->EjectQuarter();
	m_quarterCount = 0;
}

void GumballMachine::TurnCrank()
{
	m_currentState->TurnCrank();
	m_currentState->Dispense();
}

void GumballMachine::RefillBalls(size_t amount)
{
	m_currentState->Refill(amount);
}

void GumballMachine::Refill(size_t amount) noexcept
{
	m_gumCount = amount;
}

size_t GumballMachine::GetBallCount() const noexcept
{
	return m_gumCount;
}

size_t GumballMachine::GetQuarterCount() const noexcept
{
	return m_quarterCount;
}

size_t GumballMachine::GetMaxQuarterCount() const noexcept
{
	return m_maxQuartersInHoldCount;
}

std::string GumballMachine::Description() const
{
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);

	return (fmt % "multi" % m_gumCount % ((m_gumCount != 1) ? "s" : "") % m_quarterCount % ((m_quarterCount != 1) ? "s" : "") % m_currentState->Description()).str();
}

void GumballMachine::ReleaseBall()
{
	if (m_gumCount != 0)
	{
		m_echoOutput << state::msg::sold::DISPENSE_MSG;
		--m_gumCount;
		--m_quarterCount;
	}
}

void GumballMachine::SetHasQuarterState()
{
	m_currentState.reset(new state::multi::HasQuarterState(*this, m_echoOutput));
}

void GumballMachine::SetNoQuarterState()
{
	m_currentState.reset(new state::NoQuarterState(*this, m_echoOutput));
}

void GumballMachine::SetSoldOutState()
{
	m_currentState.reset(new state::multi::SoldOutState(*this, m_echoOutput));
}

void GumballMachine::SetSoldState()
{
	m_currentState.reset(new state::multi::SoldState(*this, m_echoOutput));
}

} // namespace multi

} // namespace gumball_machine
