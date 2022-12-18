#pragma once

namespace gumball_machine
{

namespace state
{

namespace msg
{

namespace has_quarter
{

constexpr auto DISPENSE_MSG = "No gumball dispensed\n";
constexpr auto EJECT_MSG = "Quarter returned\n";
constexpr auto INSERT_MSG = "You can't insert another quarter\n";
constexpr auto TURN_CRANK_MSG = "You turned...\n";

} // namespace has_quarter

} // namespace msg

} // namespace state

} // namespace gumball_machine
