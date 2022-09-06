#include "../include/pch.h"

#include "../include/RedheadDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/FlyWithWings.h"
#include "../include/SwimBehavior.h"
#include "../include/QuackBehavior.h"

RedheadDuck::RedheadDuck()
	: Duck(std::make_unique<DanceBehavior>(),
		std::make_unique<FlyWithWings>(),
		std::make_unique<SwimBehavior>(),
		std::make_unique<QuackBehavior>())
{
}

void RedheadDuck::Display() const
{
	std::cout << "I'm redhead duck" << std::endl;
}
