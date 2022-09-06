#include "../include/Duck.h"

Duck::Duck(const Strategy& danceBehavior,
	const CountedFlyStrategy& flyBehavior,
	const Strategy& swimBehavior,
	const Strategy& quackBehavior)
	: m_danceBehavior(danceBehavior)
	, m_flyBehavior(flyBehavior)
	, m_swimBehavior(swimBehavior)
	, m_quackBehavior(quackBehavior)
	, m_flightsCount()
{
}

void Duck::PerformDance() const
{
	m_danceBehavior();
}

void Duck::PerformFly()
{
	m_flyBehavior(m_flightsCount);
}

void Duck::PerformSwim() const
{
	m_swimBehavior();
}

void Duck::PerformQuack() const
{
	m_quackBehavior();
}

void Duck::SetDanceBehavior(const Strategy& danceBehavior)
{
	m_danceBehavior = danceBehavior;
}

void Duck::SetFlyBehavior(const CountedFlyStrategy& flyBehavior)
{
	m_flyBehavior = flyBehavior;
	m_flightsCount = 0;
}

void Duck::SetSwimBehavior(const Strategy& swimBehavior)
{
	m_swimBehavior = swimBehavior;
}

void Duck::SetQuackBehavior(const Strategy& quackBehavior)
{
	m_quackBehavior = quackBehavior;
}

