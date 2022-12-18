#pragma once

namespace gumball_machine
{

namespace state
{

namespace multi
{

namespace msg
{

namespace has_quarter
{

constexpr auto STATE_DSCRP_MSG = "Has %1% quarter%2%. Waiting for turn of crank\n";

constexpr auto DISPENSE_MSG = "No gumball dispensed\n";
constexpr auto EJECT_MSG = "%1% quarter%2% returned\n";
constexpr auto INSERT_MSG = "You inserted a quarter\n";
constexpr auto INSERT_AT_MAX_MSG = "You can't insert another quarter. %1% quarter%2% limit is reached\n";
constexpr auto TURN_CRANK_MSG = "You turned...\n";

} // namespace has_quarter

} // namespace msg

} // namespace multi

} // namespace state

} // namespace gumball_machine
