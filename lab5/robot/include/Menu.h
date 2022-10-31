#ifndef ROBOT_MENU_H_
#define ROBOT_MENU_H_

#include <iostream>
#include <functional>
#include <string>
#include <vector>

namespace robot
{

class Menu
{
public:
	using Command = std::function<void()>;

	Menu(std::istream& input, std::ostream& outputEcho);

	void AddItem(const std::string& shortcut, const std::string& description, const Command& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	bool ExecuteCommand(const std::string& command);

	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command);

		std::string shortcut;
		std::string description;
		Command command;
	};

	bool m_exit = false;
	std::istream& m_input;
	std::ostream& m_outputEcho;
	std::vector<Item> m_items;
};

}; // namespace robot

#endif // !ROBOT_MENU_H_
