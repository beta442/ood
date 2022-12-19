#pragma once

#include <iostream>

#include "../../IGumballMachine.h"
#include "../../state/IState.h"

namespace gumball_machine
{

namespace multi
{

class GumballMachine final : private IGumballMachine
{
public:
	using REchoStream = std::ostream&;

	explicit GumballMachine(size_t maxQuartersInHold = 1, REchoStream echoOutput = std::cout);
	explicit GumballMachine(size_t maxQuartersInHold = 1, size_t onInitBallsCount = 0, REchoStream echoOutput = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();

	size_t GetBallCount() const noexcept override;
	size_t GetQuarterCount() const noexcept override;
	size_t GetMaxQuarterCount() const noexcept override;

	std::string Description() const override;

private:
	using State = state::IStatePtr;

	void ReleaseBall() override;
	void SetHasQuarterState() override;
	void SetNoQuarterState() override;
	void SetSoldOutState() override;
	void SetSoldState() override;

	const size_t m_maxQuartersInHoldCount;
	size_t m_gumCount, m_quarterCount;
	State m_currentState;

	REchoStream m_echoOutput;
};

} // namespace multi

} // namespace gumball_machine
