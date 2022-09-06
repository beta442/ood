#ifndef SWIMBEHAVIOR_H
#define SWIMBEHAVIOR_H

#include "ISwimBehavior.h"

class SwimBehavior : public ISwimBehavior
{
public:
	void Swim() final;
};

#endif // !SWIMBEHAVIOR_H
