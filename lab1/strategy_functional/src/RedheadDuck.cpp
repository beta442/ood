#include "../include/RedheadDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/FlyBehavior.h"
#include "../include/QuackBehavior.h"
#include "../include/SwimBehavior.h"

RedheadDuck::RedheadDuck()
	: Duck(danceBehavior,
		countedFlyBehavior,
		swimBehavior,
		quackBehavior)
{
}

void RedheadDuck::Display() const
{
	std::cout << "I'm redhead duck" << std::endl;
}

