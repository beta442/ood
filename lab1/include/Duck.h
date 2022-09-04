#pragma once

#include <memory>

#include "IDanceBehavior.h"
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

class Duck
{
public:
	Duck(std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<IQuackBehavior>&& quackBehavior,
		std::unique_ptr<IDanceBehavior>&& m_danceBehavior);

	void Quack() const;
	void Swim() const;
	void Fly() const;
	void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior);

	virtual void Dance() const;
	virtual void Display() const = 0;

	virtual ~Duck() = default;

private:
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
};
