#include "pch.h"

#include "Menu.h"

namespace ui
{

namespace menu
{

Menu::Menu(RInputStream inputS, ROutputStream outputS)
	: m_input(inputS)
	, m_output(outputS)
{
}

void Menu::AddItem(const std::string& shortcut, const std::string& dscrpt, const Command& command)
{
	m_items.emplace_back(shortcut, dscrpt, command);
}

void Menu::Run()
{
	ShowInstructions();

	std::string command;
	while ((m_output << ">")
		&& std::getline(m_input, command)
		&& ExecuteCommand(command))
	{
	}
}

void Menu::ShowInstructions()
{
	m_output << "Commands list:\n";
	for (auto& item : m_items)
	{
		m_output << "--" << item.shortcut << ": " << item.description << "\n";
	}
	m_output << std::endl;
}

void Menu::Exit()
{
	m_exit = true;
}

bool Menu::ExecuteCommand(const std::string& command)
{
	std::istringstream iss(command);
	std::string name;
	iss >> name;

	m_exit = false;
	auto it = std::find_if(m_items.begin(), m_items.end(), [&name](const Item& item) {
		return utility::std_string::IEqualStrings(item.shortcut, name);
	});

	if (it != m_items.end())
	{
		it->command(iss);
	}
	else
	{
		m_output << "Unknown command\n";
	}
	return !m_exit;
}

} // namespace menu

} // namespace ui
