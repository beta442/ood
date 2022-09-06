#include "../include/pch.h"

#include "../include/ModelDuck.h"

#include "../include/DanceNoWay.h"
#include "../include/FlyNoWay.h"
#include "../include/SwimNoWay.h"
#include "../include/QuackBehavior.h"

ModelDuck::ModelDuck()
	: Duck(std::make_unique<DanceNoWay>(),
		std::make_unique<FlyNoWay>(),
		std::make_unique<SwimNoWay>(),
		std::make_unique<QuackBehavior>())
{
}

void ModelDuck::Display() const
{
	std::cout << "I'm model duck" << std::endl;
}
