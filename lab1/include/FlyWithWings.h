#pragma once

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() final;
};
