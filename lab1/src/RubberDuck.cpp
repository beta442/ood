#include "../include/pch.h"

#include "../include/RubberDuck.h"

#include "../include/FlyNoWay.h"
#include "../include/SqueakBehavior.h"

RubberDuck::RubberDuck()
	: Duck(std::make_unique<FlyNoWay>(), std::make_unique<SqueakBehavior>())
{
}
void RubberDuck::Display() const
{
	std::cout << "I'm rubber duck" << std::endl;
}

void RubberDuck::Dance() const
{
}
