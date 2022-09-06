#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() final;

private:
	static inline std::size_t m_flightCount = 0;
};

#endif // !FLYWITHWINGS_H
