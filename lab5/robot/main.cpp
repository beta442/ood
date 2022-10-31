#include "include/pch.h"

#include "include/Menu.h"
#include "include/Robot.h"

int main(int, char**)
{
	using namespace robot;

	Robot r{ std::cout };
	Menu m{ std::cin, std::cout };
	m.AddItem("on", "Turns the Robot on", [&r]() noexcept {
		r.TurnOn();
	});
	m.AddItem("off", "Turns the Robot off", [&r]() noexcept {
		r.TurnOff();
	});

	m.AddItem("north", "Makes the Robot walk north", std::bind(&Robot::Walk, &r, WalkDirection::North));
	m.AddItem("south", "Makes the Robot walk south", std::bind(&Robot::Walk, &r, WalkDirection::South));
	m.AddItem("west", "Makes the Robot walk west", std::bind(&Robot::Walk, &r, WalkDirection::West));
	m.AddItem("east", "Makes the Robot walk east", std::bind(&Robot::Walk, &r, WalkDirection::East));

	m.AddItem("stop", "Stops the Robot", std::bind(&Robot::Stop, &r));

	m.AddItem("exit", "Exits from application", [&m]() noexcept {
		m.Exit();
	});

	m.Run();

	return 0;
}
