#pragma once

#include "../BaseState.h"

namespace gumball_machine
{

namespace state
{

class NoQuarterState final : public BaseState
{
public:
	using MyBase = BaseState;

	explicit NoQuarterState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	void Dispense() override;
	void EjectQuarter() override;
	void Refill(size_t amount) override;
	void InsertQuarter() override;
	void TurnCrank() override;

private:
	std::string Description() const override;
};

} // namespace state

} // namespace gumball_machine
