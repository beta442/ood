#include "../include/pch.h"

#include "../include/CountedFly.h"

CountedFly::CountedFly()
	: m_flightCount(0)
{
}

std::size_t CountedFly::GetCounter() const
{
	return m_flightCount;
}

void CountedFly::BumpCounter()
{
	++m_flightCount;
}

void CountedFly::Fly()
{
	BumpCounter();
}
