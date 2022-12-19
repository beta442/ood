#pragma once

#include <string>
#include <unordered_map>

namespace ui
{

namespace editor
{

namespace editor_commands
{

constexpr auto EJECT_CMND = "Eject";
constexpr auto EXIT_CMND = "Exit";
constexpr auto HELP_CMND = "Help";
constexpr auto INSERT_CMND = "Insert";
constexpr auto REFILL_CMND = "Refill";
constexpr auto SHOW_CMND = "Show";
constexpr auto TURN_CRANK_CMND = "TurnCrank";


namespace descriptions
{

static const std::unordered_map<const char*, std::string> COMMAND_TO_DESCRIPTION = {
	{ EJECT_CMND, "Ejects quarter from gumball machine" },
	{ EXIT_CMND, "Stops program" },
	{ HELP_CMND, "Shows program's help message" },
	{ INSERT_CMND, "Inserts quarter into gumball machine" },
	{ REFILL_CMND, "Refill gumball machine with given amount of gumball" },
	{ SHOW_CMND, "Shows gumball machine's info" },
	{ TURN_CRANK_CMND, "Turns gumball machine's cranck" },
};

} // namespace descriptions

} // namespace editor_commands

} // namespace editor

} // namespace ui
