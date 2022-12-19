#pragma once

#include <iostream>
#include <string>

namespace gumball_machine
{

namespace multi
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

	explicit NaiveGumballMachine(size_t maxQuarterCount = 1, REchoStream echoOutput = std::cout);
	explicit NaiveGumballMachine(size_t maxQuarterCount = 1, size_t onInitBallCount = 0, REchoStream echoOutput = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	void Refill(size_t numBalls);

	size_t GetBallCount() const noexcept;
	size_t GetMaxQuarterCount() const noexcept;
	size_t GetQuarterCount() const noexcept;

	std::string Description() const;

private:
	void Dispense();

	REchoStream m_echoOutput;

	const size_t m_maxQuarterInHoldCount;
	size_t m_gumCount, m_quarterCount;
	State m_state;
};

} // namespace multi

} // namespace gumball_machine
