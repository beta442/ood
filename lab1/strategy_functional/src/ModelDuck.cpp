#include "../include/ModelDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/FlyBehavior.h"
#include "../include/SwimBehavior.h"
#include "../include/QuackBehavior.h"

ModelDuck::ModelDuck()
	: Duck(noDanceBehavior, countedFlyBehavior(), noSwimBehavior, quackBehavior)
{
}

void ModelDuck::Display() const
{
	std::cout << "I'm model duck!" << std::endl;
}

