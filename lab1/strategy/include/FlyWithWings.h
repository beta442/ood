#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
public:
	FlyWithWings();

	void Fly() final;

private:
	std::size_t m_flightCount;
};

#endif // !FLYWITHWINGS_H
