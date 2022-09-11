#include "../include/pch.h"

#include "../include/MallardDuck.h"

#include "../include/DanceBehavior.h"
#include "../include/CountedFly.h"
#include "../include/SwimBehavior.h"
#include "../include/QuackBehavior.h"

MallardDuck::MallardDuck()
	: Duck(std::make_unique<DanceBehavior>(),
		std::make_unique<CountedFly>(),
		std::make_unique<SwimBehavior>(),
		std::make_unique<QuackBehavior>())
{
}

void MallardDuck::Display() const
{
	std::cout << "I'm mallard duck" << std::endl;
}
