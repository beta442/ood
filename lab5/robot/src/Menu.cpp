#include "../include/pch.h"

#include "../include/Menu.h"

using namespace robot;

Menu::Menu(std::istream& input, std::ostream& outputEcho)
	: m_input(input)
	, m_outputEcho(outputEcho)
{
}

void Menu::AddItem(const std::string& shortcut,
	const std::string& description,
	const Command& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void Menu::Run()
{
	ShowInstructions();

	std::string command;
	while ((m_outputEcho << ">")
		&& getline(m_input, command)
		&& ExecuteCommand(command))
	{
	}
}

void Menu::ShowInstructions() const
{
	m_outputEcho << "Commands list:\n";
	for (const auto& item : m_items)
	{
		m_outputEcho << "  " << item.shortcut << ": " << item.description << "\n";
	}
}

void Menu::Exit()
{
	m_exit = true;
}

bool Menu::ExecuteCommand(const std::string& command)
{
	m_exit = false;

	auto it = std::find_if(m_items.begin(), m_items.end(), [&](const Item& item) noexcept {
		return item.shortcut == command;
	});

	if (it != m_items.end())
	{
		it->command();
	}
	else
	{
		m_outputEcho << "Unknown command\n";
	}

	return !m_exit;
}

Menu::Item::Item(const std::string& shortcut, const std::string& description, const Command& command)
	: shortcut(shortcut)
	, description(description)
	, command(command)
{
}
