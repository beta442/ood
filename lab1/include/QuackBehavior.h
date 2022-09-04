#pragma once

#include "IQuackBehavior.h"

class QuackBehavior : public IQuackBehavior
{
public:
	void Quack() final;
};
