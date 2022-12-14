#pragma once

#include "../../BaseState.h"

namespace gumball_machine
{

namespace state
{

namespace multi
{

class SoldOutState final : public BaseState
{
public:
	using MyBase = BaseState;

	explicit SoldOutState(RGumballMachine gumballMachine,
		REchoStream echoOutput = std::cout);

	void Dispense() override;
	void EjectQuarter() override;
	void Refill(size_t amount) override;
	void InsertQuarter() override;
	void TurnCrank() override;

private:
	std::string Description() const override;
};

} // namespace multi

} // namespace state

} // namespace gumball_machine
