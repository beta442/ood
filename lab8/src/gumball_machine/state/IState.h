#pragma once

#include <ostream>
#include <string>

#include "IState_fwd.h"

namespace gumball_machine
{

namespace state
{

class IState
{
public:
	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;

	virtual std::string Description() const = 0;

	virtual ~IState() = default;
};

static inline std::ostream& operator<<(std::ostream& os, const IState& state)
{
	if (!std::ostream::sentry(os))
	{
		return os;
	}

	os << state.Description();

	return os;
}

} // namespace state

} // namespace gumball_machine
