#include "pch.h"

#include "Editor.h"

#include "commands.h"

namespace ui
{

namespace editor
{

Editor::Editor(GumballMachine&& gumballMachine, RInputStream inputS, ROutputStream outputS)
	: m_gumballMachine(std::move(gumballMachine))
	, m_menu(inputS, outputS)
	, m_outputEcho(outputS)
{
	using namespace editor_commands;
	using namespace editor_commands::descriptions;

	m_menu.AddItem(EXIT_CMND, COMMAND_TO_DESCRIPTION.at(EXIT_CMND), [&menu = m_menu](RInputStream) {
		menu.Exit();
	});

	m_menu.AddItem(HELP_CMND, COMMAND_TO_DESCRIPTION.at(HELP_CMND), [&menu = m_menu](RInputStream) {
		menu.ShowInstructions();
	});

	m_menu.AddItem(SHOW_CMND, COMMAND_TO_DESCRIPTION.at(SHOW_CMND), [this](RInputStream) {
		ShowGumballMachineInfo();
	});

	m_menu.AddItem(EJECT_CMND, COMMAND_TO_DESCRIPTION.at(EJECT_CMND), [this](RInputStream is) {
		EjectQuarter();
	});

	m_menu.AddItem(INSERT_CMND, COMMAND_TO_DESCRIPTION.at(INSERT_CMND), [this](RInputStream is) {
		InsertQuarter();
	});

	m_menu.AddItem(TURN_CRANK_CMND, COMMAND_TO_DESCRIPTION.at(TURN_CRANK_CMND), [this](RInputStream is) {
		TurnCrank();
	});

	m_menu.AddItem(REFILL_CMND, COMMAND_TO_DESCRIPTION.at(REFILL_CMND), [this](RInputStream is) {
		Refill(is);
	});
}

void Editor::EjectQuarter()
{
	try
	{
		m_gumballMachine->EjectQuarter();
	}
	catch (const std::exception& e)
	{
		m_outputEcho << e.what() << std::endl;
	}
}

void Editor::InsertQuarter()
{
	try
	{
		m_gumballMachine->InsertQuarter();
	}
	catch (const std::exception& e)
	{
		m_outputEcho << e.what() << std::endl;
	}
}

constexpr auto BAD_STREAM_MSG = "Failed to read arguments. Nothing to read or input stream is bad\n";
constexpr auto BAD_ARGUMENTS_MSG = "Failed to read command's arguments. See help\n";

void Editor::Refill(RInputStream is)
{
	if (!std::istream::sentry(is))
	{
		m_outputEcho << BAD_STREAM_MSG;
		return;
	}

	size_t amount{};
	if (!(is >> amount))
	{
		m_outputEcho << BAD_ARGUMENTS_MSG;
		return;
	}

	try
	{
		m_gumballMachine->RefillBalls(amount);
	}
	catch (const std::exception& e)
	{
		m_outputEcho << e.what() << std::endl;
	}
}

void Editor::TurnCrank()
{
	try
	{
		m_gumballMachine->TurnCrank();
	}
	catch (const std::exception& e)
	{
		m_outputEcho << e.what() << std::endl;
	}
}

void Editor::Start()
{
	m_menu.Run();
}

void Editor::ShowGumballMachineInfo()
{
	m_outputEcho << m_gumballMachine->Description();
}

} // namespace editor

} // namespace ui
