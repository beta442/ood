#include "../include/pch.h"

#include "../include/FlyWithWings.h"

FlyWithWings::FlyWithWings()
	: m_flightCount(0)
{
}

void FlyWithWings::Fly()
{
	++m_flightCount;
	std::cout << "I'm flying with wings!! My flight is " << m_flightCount << std::endl;
}
