#pragma once

#include <iostream>
#include <string>

#include "../IGumballMachine.h"
#include "IState.h"

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

	std::string Description() const override = 0;

	REchoStream m_echoOutput;
	RGumballMachine m_gumballMachine;
};

} // namespace state

} // namespace gumball_machine
