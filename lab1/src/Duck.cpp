#include "../include/pch.h"

#include "../include/Duck.h"

Duck::Duck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
	std::unique_ptr<IQuackBehavior>&& quackBehavior,
	std::unique_ptr<IDanceBehavior>&& danceBehavior)
	: m_danceBehavior(std::move(danceBehavior))
	, m_quackBehavior(std::move(quackBehavior))
{
	assert(m_quackBehavior);
	SetFlyBehavior(std::move(flyBehavior));
}

void Duck::Quack() const
{
	m_quackBehavior->Quack();
}

void Duck::Swim() const
{
	std::cout << "I'm swimming" << std::endl;
}

void Duck::Fly() const
{
	m_flyBehavior->Fly();
}

void Duck::Dance() const
{
	m_danceBehavior->Dance();
}

void Duck::SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = move(flyBehavior);
}
