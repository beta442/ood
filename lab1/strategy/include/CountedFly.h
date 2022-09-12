#ifndef COUNTEDFLY_H
#define COUNTEDFLY_H

#include "IFlyBehavior.h"

class CountedFly : public IFlyBehavior
{
public:
	CountedFly();

	void Fly() override;

protected:
	void BumpCounter();
	size_t GetCounter() const;

private:
	size_t m_flightCount;
};

#endif // !COUNTEDFLY_H
