#pragma once

#include <memory>

namespace gumball_machine
{

class IGumballMachine;

using IGumballMachineRawPtr = IGumballMachine*;
using IGumballMachinePtr = std::unique_ptr<IGumballMachine>;

} // namespace gumball_machine
