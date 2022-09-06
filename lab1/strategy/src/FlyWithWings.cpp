#include "../include/pch.h"

#include "../include/FlyWithWings.h"

void FlyWithWings::Fly()
{
	++m_flightCount;
	std::cout << "I'm flying with wings!! My flight is " << m_flightCount << std::endl;
}
