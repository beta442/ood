#pragma once

namespace gumball_machine
{

namespace state
{

namespace msg
{

namespace no_quarter
{

constexpr auto DISPENSE_MSG = "You need to pay first\n";
constexpr auto EJECT_MSG = "You haven't inserted a quarter\n";
constexpr auto INSERT_MSG = "You inserted a quarter\n";
constexpr auto TURN_CRANK_MSG = "You turned but there's no quarter\n";

} // namespace no_quarter

} // namespace msg

} // namespace state

} // namespace gumball_machine
