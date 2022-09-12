#include "../include/pch.h"

#include "../include/RubberDuck.h"

#include "../include/DanceNoWay.h"
#include "../include/FlyWithWings.h"
#include "../include/SwimNoWay.h"
#include "../include/SqueakBehavior.h"

RubberDuck::RubberDuck()
	: Duck(std::make_unique<DanceNoWay>(),
		std::make_unique<FlyWithWings>(),
		std::make_unique<SwimNoWay>(),
		std::make_unique<SqueakBehavior>())
{
}

void RubberDuck::Display() const
{
	std::cout << "I'm rubber duck" << std::endl;
}
