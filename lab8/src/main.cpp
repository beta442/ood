#include "pch.h"

#include "gumball_machine/CGumballMachine/GumballMachine.h"
#include "gumball_machine/CGumballMachine/NaiveGumballMachine.h"
#include "gumball_machine/CGumballMachine/multi/MultiGumballMachine.h"
#include "gumball_machine/CGumballMachine/multi/MultiNaiveGumballMachine.h"

template <typename GumbalMachineT>
void TestGumballMachine(GumbalMachineT& m)
{
	std::cout << m.Description() << std::endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
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

	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.TurnCrank();
	m.InsertQuarter();
	m.InsertQuarter();
	m.InsertQuarter();
	m.EjectQuarter();
	m.EjectQuarter();

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

void TestGumballMachineWithMultiQuarterState()
{
	gumball_machine::multi::GumballMachine m(3, 7);
	TestGumballMachine(m);
}

void TestNaiveGumballMachineWithMultiQuarterState()
{
	gumball_machine::multi::NaiveGumballMachine m(3, 7);
	TestGumballMachine(m);
}

int main(int, char**)
{
	TestGumballMachineWithDynamicState();
	TestNaiveGumballMachine();
	TestGumballMachineWithMultiQuarterState();
	TestNaiveGumballMachineWithMultiQuarterState();

	return 0;
}
