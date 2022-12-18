#pragma once

namespace gumball_machine
{

class IGumballMachine
{
public:
	virtual void ReleaseBall() = 0;
	virtual size_t GetBallCount() const noexcept = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual ~IGumballMachine() = default;
};

} // namespace gumball_machine
