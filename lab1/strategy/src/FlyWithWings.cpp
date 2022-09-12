#include "../include/pch.h"

#include "../include/FlyWithWings.h"

void FlyWithWings::Fly()
{
	CountedFly::Fly();
	std::cout << "I'm flying with count!! My flight is " << GetCounter() << std::endl;
}
