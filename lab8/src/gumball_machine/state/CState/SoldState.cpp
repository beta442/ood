#include "pch.h"

#include "SoldState.h"
#include "msg/Sold.h"

namespace gumball_machine
{

namespace state
{

namespace msgs = msg::sold;

SoldState::SoldState(RGumballMachine gumballMachine,
	REchoStream echoOutput)
	: MyBase(gumballMachine, echoOutput)
{
}

void SoldState::Dispense()
{
	const bool zeroBallsBeforeDispenseTry = (m_gumballMachine.GetBallCount() == 0);

	(zeroBallsBeforeDispenseTry)
		? (void)(m_echoOutput << msgs::DISPENSE_ON_SOLD_OUT_MSG)
		: m_gumballMachine.ReleaseBall();

	const bool zeroBallsAfterDispenseTry = (m_gumballMachine.GetBallCount() == 0);

	(zeroBallsAfterDispenseTry)
		? m_gumballMachine.SetSoldOutState()
		: m_gumballMachine.SetNoQuarterState();
}

void SoldState::EjectQuarter()
{
	m_echoOutput << msgs::EJECT_MSG;
}

void SoldState::InsertQuarter()
{
	m_echoOutput << msgs::INSERT_MSG;
}

void SoldState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
}

std::string SoldState::Description() const
{
	return msgs::STATE_DSCRP_MSG;
}

} // namespace state

} // namespace gumball_machine
