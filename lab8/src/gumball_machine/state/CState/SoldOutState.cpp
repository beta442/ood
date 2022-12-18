#include "pch.h"

#include "SoldOutState.h"
#include "msg/SoldOut.h"

namespace gumball_machine
{

namespace state
{

namespace msgs = msg::sold_out;

SoldOutState::SoldOutState(RGumballMachine gumballMachine,
	REchoStream echoOutput)
	: MyBase(gumballMachine, echoOutput)
{
}

void SoldOutState::Dispense()
{
	m_echoOutput << msgs::DISPENSE_MSG;
}

void SoldOutState::EjectQuarter()
{
	m_echoOutput << msgs::EJECT_MSG;
}

void SoldOutState::InsertQuarter()
{
	m_echoOutput << msgs::INSERT_MSG;
}

void SoldOutState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
}

} // namespace state

} // namespace gumball_machine
