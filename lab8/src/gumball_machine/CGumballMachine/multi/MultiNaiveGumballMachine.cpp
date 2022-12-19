#include "pch.h"

#include "MultiNaiveGumballMachine.h"

#include "../../Description.h"
#include "../../state/CState/msg/all.h"
#include "../../state/CState/multi/msg/all.h"

namespace gumball_machine
{

namespace multi
{

constexpr auto INVALID_MAX_QUARTERS_IN_HOLD_MSG = "Failed to create gumball machine. Bad maxQuartersInHold argument's value = %1%";

NaiveGumballMachine::NaiveGumballMachine(size_t maxQuarterCount, REchoStream echoOutput)
	: m_gumCount(0)
	, m_state(State::SoldOut)
	, m_echoOutput(echoOutput)
	, m_quarterCount(0)
	, m_maxQuarterInHoldCount(maxQuarterCount)
{
	if (m_maxQuarterInHoldCount == 0)
	{
		throw std::invalid_argument((boost::format(INVALID_MAX_QUARTERS_IN_HOLD_MSG) % m_maxQuarterInHoldCount).str());
	}
}

NaiveGumballMachine::NaiveGumballMachine(size_t maxQuarterCount, size_t onInitBallCount, REchoStream echoOutput)
	: m_gumCount(onInitBallCount)
	, m_state((onInitBallCount > 0) ? State::NoQuarter : State::SoldOut)
	, m_echoOutput(echoOutput)
	, m_quarterCount(0)
	, m_maxQuarterInHoldCount(maxQuarterCount)
{
	if (m_maxQuarterInHoldCount == 0)
	{
		throw std::invalid_argument((boost::format(INVALID_MAX_QUARTERS_IN_HOLD_MSG) % m_maxQuarterInHoldCount).str());
	}
}

namespace msgs = state::msg;
namespace msgs_multi = state::multi::msg;

void NaiveGumballMachine::InsertQuarter()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << ((m_quarterCount < m_maxQuarterInHoldCount)
				? msgs_multi::has_quarter::INSERT_MSG
				: (boost::format(msgs_multi::has_quarter::INSERT_AT_MAX_MSG) % m_quarterCount % ((m_quarterCount != 1) ? "s" : "")).str());
		if (m_quarterCount < m_maxQuarterInHoldCount)
		{
			++m_quarterCount;
		}
		break;
	}
	case State::NoQuarter: {
		m_echoOutput << msgs::no_quarter::INSERT_MSG;
		m_state = State::HasQuarter;
		if (m_quarterCount < m_maxQuarterInHoldCount)
		{
			++m_quarterCount;
		}
		break;
	}
	case State::Sold: {
		m_echoOutput << msgs::sold::INSERT_MSG;
		break;
	}
	case State::SoldOut: {
		m_echoOutput << msgs_multi::sold_out::INSERT_MSG;
		break;
	}
	}
}

void NaiveGumballMachine::EjectQuarter()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << (boost::format(msgs_multi::has_quarter::EJECT_MSG) % m_quarterCount % ((m_quarterCount != 1) ? "s" : "")).str();
		m_state = State::NoQuarter;
		m_quarterCount = 0;
		break;
	}
	case State::NoQuarter: {
		m_echoOutput << msgs::no_quarter::EJECT_MSG;
		break;
	}
	case State::Sold: {
		m_echoOutput << msgs::sold::EJECT_MSG;
		break;
	}
	case State::SoldOut: {
		m_echoOutput << ((m_quarterCount != 0)
				? (boost::format(msgs_multi::sold_out::EJECT_MSG) % m_quarterCount % ((m_quarterCount != 1) ? "s" : "")).str()
				: msgs_multi::sold_out::EJECT_ON_NO_QUARTERS_MSG);
		m_quarterCount = 0;
		break;
	}
	}
}

void NaiveGumballMachine::TurnCrank()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << msgs_multi::has_quarter::TURN_CRANK_MSG;
		m_state = State::Sold;
		Dispense();
		break;
	}
	case State::NoQuarter: {
		m_echoOutput << msgs::no_quarter::TURN_CRANK_MSG;
		break;
	}
	case State::Sold: {
		m_echoOutput << msgs::sold::TURN_CRANK_MSG;
		break;
	}
	case State::SoldOut: {
		m_echoOutput << msgs_multi::sold_out::TURN_CRANK_MSG;
		break;
	}
	}
}

void NaiveGumballMachine::Refill(size_t numBalls)
{
	m_gumCount = numBalls;
	m_state = (numBalls > 0)
		? State::NoQuarter
		: State::SoldOut;
}

std::string NaiveGumballMachine::Description() const
{
	std::string state = (m_state == State::SoldOut)
		? msgs_multi::sold_out::STATE_DSCRP_MSG
		: (m_state == State::NoQuarter)
		? msgs::no_quarter::STATE_DSCRP_MSG
		: (m_state == State::HasQuarter)
		? (boost::format(msgs_multi::has_quarter::STATE_DSCRP_MSG) % m_quarterCount % ((m_quarterCount != 1) ? "s" : "")).str()
		: msgs::sold::STATE_DSCRP_MSG;
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);

	return (fmt % "naive" % m_gumCount % (m_gumCount != 1 ? "s" : "") % m_quarterCount % ((m_quarterCount != 1) ? "s" : "") % state).str();
}

void NaiveGumballMachine::Dispense()
{
	switch (m_state)
	{
	case State::Sold: {
		bool zeroGumballs = (m_gumCount == 0);
		if (!zeroGumballs)
		{
			--m_gumCount;
			--m_quarterCount;
		}
		bool zeroBallsAfterDispense = (m_gumCount == 0);
		bool zeroQuartersAfterDispenseTry = (m_quarterCount == 0);
		if (zeroBallsAfterDispense)
		{
			m_state = State::SoldOut;
		}
		else if (zeroQuartersAfterDispenseTry)
		{
			m_state = State::NoQuarter;
		}
		else
		{
			m_state = State::HasQuarter;
		}
		m_echoOutput << ((zeroGumballs)
				? msgs::sold::DISPENSE_ON_SOLD_OUT_MSG
				: msgs::sold::DISPENSE_MSG);
		break;
	}
	case State::NoQuarter:
		m_echoOutput << msgs::no_quarter::DISPENSE_MSG;
		break;
	case State::SoldOut:
	case State::HasQuarter:
		m_echoOutput << msgs::has_quarter::DISPENSE_MSG;
		break;
	}
}

} // namespace multi

} // namespace gumball_machine
