#pragma once

namespace gumball_machine
{

namespace state
{

namespace msg
{

namespace sold_out
{

constexpr auto STATE_DSCRP_MSG = "Sold out. Waiting for refill\n";

constexpr auto DISPENSE_MSG = "No gumball dispensed\n";
constexpr auto EJECT_MSG = "You can't eject, you haven't inserted a quarter yet\n";
constexpr auto INSERT_MSG = "You can't insert a quarter, the machine is sold out\n";
constexpr auto TURN_CRANK_MSG = "You turned but there's no gumballs\n";

} // namespace sold_out

} // namespace msg

} // namespace state

} // namespace gumball_machine
