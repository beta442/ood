#pragma once

#include <ostream>
#include <string>

namespace gumball_machine
{

class IGumballMachine
{
public:
	virtual void ReleaseBall() = 0;
	virtual void Refill(size_t) noexcept = 0;

	virtual size_t GetBallCount() const noexcept = 0;
	virtual size_t GetQuarterCount() const noexcept = 0;
	virtual size_t GetMaxQuarterCount() const noexcept = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;

	virtual std::string Description() const = 0;

	virtual ~IGumballMachine() = default;
};

static inline std::ostream& operator<<(std::ostream& os, const IGumballMachine& machine)
{
	if (!std::ostream::sentry(os))
	{
		return os;
	}

	os << machine.Description();

	return os;
}

} // namespace gumball_machine
