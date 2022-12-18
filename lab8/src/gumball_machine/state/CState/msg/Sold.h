#pragma once

namespace gumball_machine
{

namespace state
{

namespace msg
{

namespace sold
{

constexpr auto STATE_DSCRP_MSG = "Sold. Delivering a gumball\n";

constexpr auto DISPENSE_MSG = "A gumball comes rolling out the slot\n";
constexpr auto DISPENSE_ON_SOLD_OUT_MSG = "Oops, out of gumballs\n";
constexpr auto EJECT_MSG = "Sorry you already turned the crank\n";
constexpr auto INSERT_MSG = "Please wait, we're already giving you a gumball\n";
constexpr auto TURN_CRANK_MSG = "Turning twice doesn't get you another gumball\n";

} // namespace sold

} // namespace msg

} // namespace state

} // namespace gumball_machine
