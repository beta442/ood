#include "../include/pch.h"

#include "../include/CountedFly.h"

CountedFly::CountedFly()
	: m_flightCount(0)
{
}

void CountedFly::BumpCounter()
{
	++m_flightCount;
}

void CountedFly::Fly()
{
	BumpCounter();
	std::cout << "I'm flying with wings!! My flight is " << m_flightCount << std::endl;
}
