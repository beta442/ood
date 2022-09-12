#include "../include/MallardDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/FlyBehavior.h"
#include "../include/SwimBehavior.h"
#include "../include/QuackBehavior.h"

MallardDuck::MallardDuck()
	: Duck(danceBehavior, countedFlyBehavior, swimBehavior, quackBehavior)
{
}

void MallardDuck::Display() const
{
	std::cout << "I'm mallard duck" << std::endl;
}

