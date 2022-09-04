#pragma once

#include "IDanceBehavior.h"

class DanceBehavior : public IDanceBehavior
{
public:
	void Dance() final;
};
