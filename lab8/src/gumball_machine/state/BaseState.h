#pragma once

#include <iostream>

#include "IState.h"
#include "../IGumballMachine.h"

namespace gumball_machine
{

namespace state
{

class BaseState : public IState
{
protected:
	using RGumballMachine = IGumballMachine&;
	using REchoStream = std::ostream&;

	explicit BaseState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	REchoStream m_echoOutput;
	RGumballMachine m_gumballMachine;
};

} // namespace state

} // namespace gumball_machine
