#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include "pch.h"

const std::function<void(std::size_t&)> flyWithWingsBehavior{
	[](auto&) {
		std::cout << "I'm flying with wings!" << std::endl;
	}
};

const std::function<void(std::size_t&)> noFlyBehavior{
	[](auto&) {}
};

const std::function<void(std::size_t&)> countedFlyBehavior{
	[](std::size_t& flightCount) {
		++flightCount;
		std::cout << "I'm flying with wings! I'm " << flightCount << std::endl;
	}
};

#endif // !FLYBEHAVIOR_H
