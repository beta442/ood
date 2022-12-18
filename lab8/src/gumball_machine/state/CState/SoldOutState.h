#pragma once

#include "../BaseState.h"

namespace gumball_machine
{

namespace state
{

class SoldOutState final : public BaseState
{
public:
	using MyBase = BaseState;

	explicit SoldOutState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	void Dispense() override;
	void EjectQuarter() override;
	void InsertQuarter() override;
	void TurnCrank() override;
};

} // namespace state

} // namespace gumball_machine
