#pragma once

#include <memory>

namespace gumball_machine
{

namespace state
{

class IState;

using IStateRawPtr = IState*;

using IStatePtr = std::unique_ptr<IState>;
using IStateSharedPtr = std::shared_ptr<IState>;
using IStateWeakPtr = std::weak_ptr<IState>;

} // namespace state

} // namespace gumball_machine
