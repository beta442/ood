#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include "pch.h"

static const std::function<void()> flyWithWingsBehavior{
	[]() {
		std::cout << "I'm flying with wings!" << std::endl;
	}
};

static const std::function<void()> noFlyBehavior{
	[]() {}
};

static const std::function<void()> countedFlyBehavior{
	[flightCount = 0]() mutable -> void {
		++flightCount;
		std::cout << "I'm flying with wings! I'm " << flightCount << std::endl;
	}
};

#endif // !FLYBEHAVIOR_H
