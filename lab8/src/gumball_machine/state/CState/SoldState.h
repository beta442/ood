#pragma once

#include <ostream>

#include "../BaseState.h"

namespace gumball_machine
{

namespace state
{

class SoldState final : public BaseState
{
public:
	using MyBase = BaseState;

	explicit SoldState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	void Dispense() override;
	void EjectQuarter() override;
	void InsertQuarter() override;
	void TurnCrank() override;

private:
	std::string Description() const override;
};

} // namespace state

} // namespace gumball_machine
