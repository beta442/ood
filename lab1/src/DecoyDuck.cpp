#include "../include/pch.h"

#include "../include/DecoyDuck.h"

#include "../include/DanceNoWay.h"
#include "../include/FlyNoWay.h"
#include "../include/MuteQuackBehavior.h"

DecoyDuck::DecoyDuck()
	: Duck(std::make_unique<FlyNoWay>(), std::make_unique<MuteQuackBehavior>(), std::make_unique<DanceNoWay>())
{
}

void DecoyDuck::Display() const
{
	std::cout << "I'm decoy duck" << std::endl;
}
