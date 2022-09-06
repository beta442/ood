#ifndef DUCK_H
#define DUCK_H

#include <functional>

class Duck
{
public:
	using Strategy = std::function<void()>;
	using CountedFlyStrategy = std::function<void(std::size_t&)>;

	Duck(const Strategy& danceBehavior,
		const CountedFlyStrategy& aFlyBehavior,
		const Strategy& swimBehavior,
		const Strategy& quackBehavior);

	void Dance() const;
	void Fly();
	void Swim() const;
	void Quack() const;
	void SetDanceBehavior(const Strategy& danceBehavior);
	void SetFlyBehavior(const CountedFlyStrategy& flyBehavior);
	void SetSwimBehavior(const Strategy& swimBehavior);
	void SetQuackBehavior(const Strategy& quackBehavior);

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	Strategy m_danceBehavior;
	CountedFlyStrategy m_flyBehavior;
	Strategy m_swimBehavior;
	Strategy m_quackBehavior;

	std::size_t m_flightsCount;
};
#endif // !DUCK_H
