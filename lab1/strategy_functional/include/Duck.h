#ifndef DUCK_H
#define DUCK_H

#include <functional>

class Duck
{
public:
	using Strategy = std::function<void()>;

	Duck(const Strategy& danceBehavior,
		const Strategy& aFlyBehavior,
		const Strategy& swimBehavior,
		const Strategy& quackBehavior);

	void PerformDance() const;
	void PerformFly();
	void PerformSwim() const;
	void PerformQuack() const;
	void SetDanceBehavior(const Strategy& danceBehavior);
	void SetFlyBehavior(const Strategy& flyBehavior);
	void SetSwimBehavior(const Strategy& swimBehavior);
	void SetQuackBehavior(const Strategy& quackBehavior);

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	Strategy m_danceBehavior;
	Strategy m_flyBehavior;
	Strategy m_swimBehavior;
	Strategy m_quackBehavior;
};
#endif // !DUCK_H
