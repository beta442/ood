#include "pch.h"

#include "NaiveGumballMachine.h"

#include "../Description.h"
#include "../state/CState/msg/all.h"

namespace gumball_machine
{

NaiveGumballMachine::NaiveGumballMachine(REchoStream echoOutput)
	: m_gumCount(0)
	, m_state(State::SoldOut)
	, m_echoOutput(echoOutput)
{
}

NaiveGumballMachine::NaiveGumballMachine(size_t onInitBallCount, REchoStream echoOutput)
	: m_gumCount(onInitBallCount)
	, m_state((onInitBallCount > 0) ? State::NoQuarter : State::SoldOut)
	, m_echoOutput(echoOutput)
{
}

namespace msgs = state::msg;

void NaiveGumballMachine::InsertQuarter()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << msgs::has_quarter::INSERT_MSG;
		break;
	}
	case State::NoQuarter: {
		m_echoOutput << msgs::no_quarter::INSERT_MSG;
		m_state = State::HasQuarter;
		break;
	}
	case State::Sold: {
		m_echoOutput << msgs::sold::INSERT_MSG;
		break;
	}
	case State::SoldOut: {
		m_echoOutput << msgs::sold_out::INSERT_MSG;
		break;
	}
	}
}

void NaiveGumballMachine::EjectQuarter()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << msgs::has_quarter::EJECT_MSG;
		m_state = State::NoQuarter;
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
		m_echoOutput << msgs::sold_out::EJECT_MSG;
		break;
	}
	}
}

void NaiveGumballMachine::TurnCrank()
{
	switch (m_state)
	{
	case State::HasQuarter: {
		m_echoOutput << msgs::has_quarter::TURN_CRANK_MSG;
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
		m_echoOutput << msgs::sold_out::TURN_CRANK_MSG;
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
		? msgs::sold_out::STATE_DSCRP_MSG
		: (m_state == State::NoQuarter)
		? msgs::no_quarter::STATE_DSCRP_MSG
		: (m_state == State::HasQuarter)
		? msgs::has_quarter::STATE_DSCRP_MSG
		: msgs::sold::STATE_DSCRP_MSG;
	auto fmt = boost::format(gumball_machine::dscrp::BOOST_FORMAT_MACHINE_WITH_STATE_DSCRP);

	return (fmt % "naive" % m_gumCount % (m_gumCount != 1 ? "s" : "") % 0 % ((0 != 1) ? "s" : "") % state).str();
}

void NaiveGumballMachine::Dispense()
{
	switch (m_state)
	{
	case State::Sold: {
		bool zeroGumballs = m_gumCount == 0;
		m_gumCount = (zeroGumballs)
			? m_gumCount
			: --m_gumCount;
		m_state = (zeroGumballs)
			? State::SoldOut
			: State::NoQuarter;
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

} // namespace gumball_machine
