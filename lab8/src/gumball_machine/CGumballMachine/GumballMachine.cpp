#include "pch.h"

#include "GumballMachine.h"

#include "../state/CState/HasQuarterState.h"
#include "../state/CState/NoQuarterState.h"
#include "../state/CState/SoldOutState.h"
#include "../state/CState/SoldState.h"

#include "../Description.h"
#include "../state/CState/msg/Sold.h"

namespace gumball_machine
{

GumballMachine::GumballMachine(REchoStream echoOutput)
	: m_count(0)
	, m_echoOutput(echoOutput)
	, m_currentState(new state::SoldOutState(*this, m_echoOutput))
{
}

GumballMachine::GumballMachine(size_t ballsCount, REchoStream echoOutput)
	: m_count(ballsCount)
	, m_echoOutput(echoOutput)
	, m_currentState()
{
	(ballsCount > 0)
		? SetNoQuarterState()
		: SetSoldOutState();
}

void GumballMachine::InsertQuarter()
{
	m_currentState->InsertQuarter();
}

void GumballMachine::EjectQuarter()
{
	m_currentState->EjectQuarter();
}

void GumballMachine::TurnCrank()
{
	m_currentState->TurnCrank();
	m_currentState->Dispense();
}

void GumballMachine::ReleaseBall()
{
	namespace msgs = state::msg::sold;

	if (m_count != 0)
	{
		m_echoOutput << msgs::DISPENSE_MSG;
		--m_count;
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
	return m_count;
}

std::string GumballMachine::Description() const
{
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);

	return (fmt % "dynamic" % m_count % (m_count != 1 ? "s" : "") % m_currentState->Description()).str();
}

} // namespace gumball_machine
