#include "pch.h"

#include "gumball_machine/CGumballMachine/GumballMachine.h"

void TestGumballMachine(gumball_machine::GumballMachine& m)
{
	// std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();

	// std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.EjectQuarter();
	m.TurnCrank();

	// std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.EjectQuarter();

	// std::cout << m.ToString() << std::endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();

	// std::cout << m.ToString() << std::endl;
}

void TestGumballMachineWithDynamicState()
{
	using namespace gumball_machine;

	GumballMachine m(5);
	TestGumballMachine(m);
}

int main(int, char**)
{
	TestGumballMachineWithDynamicState();

	return 0;
}
