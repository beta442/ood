#pragma once

#include "ISwimBehavior.h"

class SwimNoWay : public ISwimBehavior
{
public:
	void Swim() final;
};
