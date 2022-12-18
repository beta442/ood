#pragma once

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

	// virtual std::string ToString() const = 0;

	virtual ~IState() = default;
};

} // namespace state

} // namespace gumball_machine
