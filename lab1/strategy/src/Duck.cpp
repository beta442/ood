#include "../include/pch.h"

#include "../include/Duck.h"

Duck::Duck(std::unique_ptr<IDanceBehavior>&& danceBehavior,
	std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<ISwimBehavior>&& swimBehavior,
	std::unique_ptr<IQuackBehavior>&& quackBehavior)
	: m_danceBehavior(std::move(danceBehavior))
	, m_flyBehavior(std::move(flyBehavior))
	, m_swimBehavior(std::move(swimBehavior))
	, m_quackBehavior(std::move(quackBehavior))
{
	assert(m_danceBehavior);
	assert(m_flyBehavior);
	assert(m_swimBehavior);
	assert(m_quackBehavior);
}

void Duck::Dance() const
{
	m_danceBehavior->Dance();
}

void Duck::Fly() const
{
	m_flyBehavior->Fly();
}

void Duck::Swim() const
{
	m_swimBehavior->Swim();
}

void Duck::Quack() const
{
	m_quackBehavior->Quack();
}

void Duck::SetDanceBehavior(std::unique_ptr<IDanceBehavior>&& danceBehavior)
{
	assert(danceBehavior);
	m_danceBehavior = std::move(danceBehavior);
}

void Duck::SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = std::move(flyBehavior);
}

void Duck::SetSwimBehavior(std::unique_ptr<ISwimBehavior>&& swimBehavior)
{
	assert(swimBehavior);
	m_swimBehavior = std::move(swimBehavior);
}

void Duck::SetQuackBehavior(std::unique_ptr<IQuackBehavior>&& quackBehavior)
{
	assert(quackBehavior);
	m_quackBehavior = std::move(quackBehavior);
}
