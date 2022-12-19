#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace ui
{

namespace menu
{

class Menu
{
public:
	using RInputStream = std::istream&;
	using ROutputStream = std::ostream&;
	using Command = std::function<void(RInputStream)>;

	Menu(RInputStream inputS, ROutputStream outputS);

	void AddItem(const std::string& shortcut, const std::string& dscrpt, const Command& command);
	void Run();
	void ShowInstructions();
	void Exit();

private:
	bool ExecuteCommand(const std::string& command);

	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}

		std::string shortcut{};
		std::string description{};
		Command command{};
	};

	RInputStream m_input;
	ROutputStream m_output;

	std::vector<Item> m_items;
	bool m_exit = false;
};

} // namespace menu

} // namespace ui
