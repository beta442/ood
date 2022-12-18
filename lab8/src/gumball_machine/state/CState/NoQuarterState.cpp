#include "pch.h"

#include "NoQuarterState.h"
#include "msg/NoQuarter.h"

namespace gumball_machine
{

namespace state
{

namespace msgs = msg::no_quarter;

NoQuarterState::NoQuarterState(RGumballMachine gumballMachine, REchoStream echoOutput)
	: MyBase(gumballMachine, echoOutput)
{
}

void NoQuarterState::Dispense()
{
	m_echoOutput << msgs::DISPENSE_MSG;
}

void NoQuarterState::EjectQuarter()
{
	m_echoOutput << msgs::EJECT_MSG;
}

void NoQuarterState::InsertQuarter()
{
	m_echoOutput << msgs::INSERT_MSG;
	m_gumballMachine.SetHasQuarterState();
}

void NoQuarterState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
}

} // namespace state

} // namespace gumball_machine
