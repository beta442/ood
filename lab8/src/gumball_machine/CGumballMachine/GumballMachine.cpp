#include "pch.h"

#include "GumballMachine.h"

#include "../state/CState/HasQuarterState.h"
#include "../state/CState/NoQuarterState.h"
#include "../state/CState/SoldOutState.h"
#include "../state/CState/SoldState.h"

namespace gumball_machine
{

GumballMachine::GumballMachine(REchoStream echoOutput)
	: m_count(0)
	, m_currentState(std::make_unique<state::SoldOutState>(*this, m_echoOutput))
	, m_echoOutput(echoOutput)
{
}

GumballMachine::GumballMachine(size_t ballsCount, REchoStream echoOutput)
	: m_count(ballsCount)
	, m_currentState()
	, m_echoOutput(echoOutput)
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

constexpr auto MSG_RELEASE_BALL = "A gumball comes rolling out the slot...\n";

void GumballMachine::ReleaseBall()
{
	if (m_count != 0)
	{
		m_echoOutput << MSG_RELEASE_BALL;
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

} // namespace gumball_machine
