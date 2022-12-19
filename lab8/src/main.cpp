#include "pch.h"

#include "gumball_machine/CGumballMachine/multi/MultiGumballMachine.h"
#include "ui/editor/Editor.h"

int main(int, char**)
{
	using namespace gumball_machine::multi;
	using namespace ui::editor;

	auto gMachine = std::make_unique<GumballMachine>(5, 0, std::cout);
	Editor editor{ std::move(gMachine), std::cin, std::cout };
	editor.Start();

	return 0;
}
