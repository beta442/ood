#include "pch.h"

#include "MultiSoldOutState.h"
#include "msg/SoldOut.h"

namespace gumball_machine
{

namespace state
{

namespace multi
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
	const auto quartersCount = m_gumballMachine.GetQuarterCount();
	m_echoOutput << ((quartersCount != 0)
			? (boost::format(msgs::EJECT_MSG) % quartersCount % ((quartersCount != 1) ? "s" : "")).str()
			: msgs::EJECT_ON_NO_QUARTERS_MSG);
}

void SoldOutState::InsertQuarter()
{
	m_echoOutput << msgs::INSERT_MSG;
}

void SoldOutState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
}

std::string SoldOutState::Description() const
{
	return msgs::STATE_DSCRP_MSG;
}

} // namespace multi

} // namespace state

} // namespace gumball_machine
