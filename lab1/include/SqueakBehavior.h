#pragma once

#include "IQuackBehavior.h"

class SqueakBehavior : public IQuackBehavior
{
public:
	void Quack() final;
};
