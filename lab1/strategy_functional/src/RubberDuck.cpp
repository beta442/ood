#include "../include/RubberDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/FlyBehavior.h"
#include "../include/QuackBehavior.h"
#include "../include/SwimBehavior.h"

RubberDuck::RubberDuck()
	: Duck(noDanceBehavior,
		countedFlyBehavior(),
		noSwimBehavior,
		squeakBehavior)
{
}

void RubberDuck::Display() const
{
	std::cout << "I'm rubber duck" << std::endl;
}

