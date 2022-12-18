#include "pch.h"

#include "../msg/Sold.h"
#include "MultiSoldState.h"

namespace gumball_machine
{

namespace state
{

namespace multi
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
	const bool zeroQuartersAfterDispenseTry = (m_gumballMachine.GetQuarterCount() == 0);

	if (zeroBallsAfterDispenseTry)
	{
		m_gumballMachine.SetSoldOutState();
	}
	else if (zeroQuartersAfterDispenseTry)
	{
		m_gumballMachine.SetNoQuarterState();
	}
	else
	{
		m_gumballMachine.SetHasQuarterState();
	}
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

} // namespace multi

} // namespace state

} // namespace gumball_machine
