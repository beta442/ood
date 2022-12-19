#pragma once

#include "../../gumball_machine/CGumballMachine/multi/MultiGumballMachine.h"
#include "../menu/Menu.h"

namespace ui
{

namespace editor
{

class Editor
{
public:
	using Menu = menu::Menu;
	using RInputStream = Menu::RInputStream;
	using ROutputStream = Menu::ROutputStream;

	using GumballMachine = std::unique_ptr<gumball_machine::multi::GumballMachine>;

	Editor(GumballMachine&& gumballMachine, RInputStream menuInput, ROutputStream menuOutput);

	void Start();

private:
	void EjectQuarter();
	void InsertQuarter();
	void Refill(RInputStream is);
	void TurnCrank();

	void ShowGumballMachineInfo();

	GumballMachine m_gumballMachine;
	Menu m_menu;

	ROutputStream m_outputEcho;
};

} // namespace editor

} // namespace ui
