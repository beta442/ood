#pragma once

#include "../BaseState.h"

namespace gumball_machine
{

namespace state
{

class HasQuarterState final : public BaseState
{
public:
	using MyBase = BaseState;

	explicit HasQuarterState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	void Dispense() override;
	void EjectQuarter() override;
	void InsertQuarter() override;
	void TurnCrank() override;
};

} // namespace state

} // namespace gumball_machine
