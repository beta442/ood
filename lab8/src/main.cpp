#include "pch.h"

#include "gumball_machine/CGumballMachine/GumballMachine.h"
#include "gumball_machine/CGumballMachine/NaiveGumballMachine.h"

template <typename GumbalMachineT>
void TestGumballMachine(GumbalMachineT& m)
{
	std::cout << m.Description() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();

	std::cout << '\n'
			  << m.Description() << std::endl;

	m.InsertQuarter();
	m.EjectQuarter();
	m.TurnCrank();

	std::cout << '\n'
			  << m.Description() << std::endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.EjectQuarter();

	std::cout << '\n'
			  << m.Description() << std::endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();

	std::cout << '\n'
			  << m.Description() << std::endl;
}

void TestNaiveGumballMachine()
{
	gumball_machine::NaiveGumballMachine m(5);
	TestGumballMachine(m);
}

void TestGumballMachineWithDynamicState()
{
	gumball_machine::GumballMachine m(5);
	TestGumballMachine(m);
}

int main(int, char**)
{
	TestGumballMachineWithDynamicState();
	TestNaiveGumballMachine();

	return 0;
}
