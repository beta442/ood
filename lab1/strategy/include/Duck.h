#ifndef DUCK_H
#define DUCK_H

#include <memory>

#include "IDanceBehavior.h"
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"
#include "ISwimBehavior.h"

class Duck
{
public:
	Duck(std::unique_ptr<IDanceBehavior>&& danceBehavior,
		std::unique_ptr<IFlyBehavior>&& flyBehavior,
		std::unique_ptr<ISwimBehavior>&& swimBehavior,
		std::unique_ptr<IQuackBehavior>&& quackBehavior);

	void PerformDance() const;
	void PerfromFly() const;
	void PerformSwim() const;
	void PerformQuack() const;
	void SetDanceBehavior(std::unique_ptr<IDanceBehavior>&& danceBehavior);
	void SetFlyBehavior(std::unique_ptr<IFlyBehavior>&& flyBehavior);
	void SetSwimBehavior(std::unique_ptr<ISwimBehavior>&& swimBehavior);
	void SetQuackBehavior(std::unique_ptr<IQuackBehavior>&& quackBehavior);

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<ISwimBehavior> m_swimBehavior;
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
};

#endif // !DUCK_H
