#pragma once

#include <iostream>
#include <string>

namespace gumball_machine
{

class NaiveGumballMachine final
{
public:
	using REchoStream = std::ostream&;

	enum class State
	{
		SoldOut = 0,
		NoQuarter,
		HasQuarter,
		Sold,
	};

	explicit NaiveGumballMachine(REchoStream echoOutput = std::cout);
	explicit NaiveGumballMachine(size_t initGumCount, REchoStream echoOutput = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	void Refill(size_t numBalls);

	std::string Description() const;

private:
	void Dispense();

	REchoStream m_echoOutput;

	size_t m_count;
	State m_state;
};

} // namespace gumball_machine
