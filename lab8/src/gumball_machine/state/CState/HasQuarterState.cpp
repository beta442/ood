#include "pch.h"

#include "HasQuarterState.h"
#include "msg/HasQuarter.h"

namespace gumball_machine
{

namespace state
{

namespace msgs = msg::has_quarter;

HasQuarterState::HasQuarterState(RGumballMachine gumballMachine,
	REchoStream echoOutput)
	: MyBase(gumballMachine, echoOutput)
{
}

void HasQuarterState::Dispense()
{
	m_echoOutput << msgs::DISPENSE_MSG;
}

void HasQuarterState::EjectQuarter()
{
	m_echoOutput << msgs::EJECT_MSG;
	m_gumballMachine.SetNoQuarterState();
}

void HasQuarterState::InsertQuarter()
{
	m_echoOutput << msgs::INSERT_MSG;
}

void HasQuarterState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
	m_gumballMachine.SetSoldState();
}

} // namespace state

} // namespace gumball_machine
