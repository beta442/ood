#include "pch.h"

#include "BaseState.h"

namespace gumball_machine
{

namespace state
{

BaseState::BaseState(RGumballMachine gumballMachine, REchoStream echoOutput)
	: m_echoOutput(echoOutput)
	, m_gumballMachine(gumballMachine)
{
}

} // namespace state

} // namespace gumball_machine
