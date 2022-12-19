#include "pch.h"

#include "../msg/common.h"
#include "MultiHasQuarterState.h"
#include "msg/HasQuarter.h"

namespace gumball_machine
{

namespace state
{

namespace multi
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
	const auto quarterCount = m_gumballMachine.GetQuarterCount();
	m_echoOutput << (boost::format(msgs::EJECT_MSG) % quarterCount % ((quarterCount != 1) ? "s" : "")).str();
	m_gumballMachine.SetNoQuarterState();
}

void HasQuarterState::InsertQuarter()
{
	const auto quarterCount = m_gumballMachine.GetQuarterCount();
	m_echoOutput << ((quarterCount < m_gumballMachine.GetMaxQuarterCount())
			? msgs::INSERT_MSG
			: (boost::format(msgs::INSERT_AT_MAX_MSG) % quarterCount % ((quarterCount != 1) ? "s" : "")).str());
}

void HasQuarterState::Refill(size_t amount)
{
	m_gumballMachine.Refill(amount);
	m_echoOutput << (boost::format(state::msg::common::REFILL_MSG) % amount % ((amount != 1) ? "s" : "")).str();
}

void HasQuarterState::TurnCrank()
{
	m_echoOutput << msgs::TURN_CRANK_MSG;
	m_gumballMachine.SetSoldState();
}

std::string HasQuarterState::Description() const
{
	const auto quarterCount = m_gumballMachine.GetQuarterCount();
	return (boost::format(msgs::STATE_DSCRP_MSG) % quarterCount % ((quarterCount != 1) ? "s" : "")).str();
}

} // namespace multi

} // namespace state

} // namespace gumball_machine
