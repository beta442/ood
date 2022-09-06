#pragma once

#include "ISwimBehavior.h"

class SwimBehavior : public ISwimBehavior
{
public:
	void Swim() final;
};
