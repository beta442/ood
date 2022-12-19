#include "pch.h"

#include "GumballMachine.h"

#include "../state/CState/HasQuarterState.h"
#include "../state/CState/NoQuarterState.h"
#include "../state/CState/SoldOutState.h"
#include "../state/CState/SoldState.h"

#include "../Description.h"
#include "../state/CState/msg/Sold.h"
#include "../state/CState/msg/HasQuarter.h"

namespace gumball_machine
{

GumballMachine::GumballMachine(REchoStream echoOutput)
	: m_gumCount(0)
	, m_echoOutput(echoOutput)
	, m_currentState(new state::SoldOutState(*this, m_echoOutput))
	, m_quarterCount(0)
{
}

GumballMachine::GumballMachine(size_t onInitBallsCount, REchoStream echoOutput)
	: m_gumCount(onInitBallsCount)
	, m_echoOutput(echoOutput)
	, m_currentState()
	, m_quarterCount(0)
{
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

void GumballMachine::Refill(size_t) noexcept
{
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
	m_currentState.reset(new state::HasQuarterState(*this, m_echoOutput));
}

void GumballMachine::SetNoQuarterState()
{
	m_currentState.reset(new state::NoQuarterState(*this, m_echoOutput));
}

void GumballMachine::SetSoldOutState()
{
	m_currentState.reset(new state::SoldOutState(*this, m_echoOutput));
}

void GumballMachine::SetSoldState()
{
	m_currentState.reset(new state::SoldState(*this, m_echoOutput));
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
	return 1;
}

std::string GumballMachine::Description() const
{
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);

	return (fmt % "dynamic" % m_gumCount % ((m_gumCount != 1) ? "s" : "") % m_quarterCount % ((m_quarterCount != 1) ? "s" : "") % m_currentState->Description()).str();
}

} // namespace gumball_machine
