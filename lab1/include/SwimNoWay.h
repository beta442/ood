#ifndef SWIMNOWAY_H
#define SWIMNOWAY_H

#include "ISwimBehavior.h"

class SwimNoWay : public ISwimBehavior
{
public:
	void Swim() final;
};

#endif // !SWIMNOWAY_H
