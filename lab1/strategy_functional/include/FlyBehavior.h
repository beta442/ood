#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include "pch.h"

const std::function<void()> flyWithWingsBehavior{
	[]() {
		std::cout << "I'm flying with wings!" << std::endl;
	}
};

const std::function<void()> noFlyBehavior{
	[]() {}
};

const std::function<std::function<void()>()> countedFlyBehavior{
	[]() {
		static std::size_t flightCount = 0;

		return [&]() {
			++flightCount;
			std::cout << "I'm flying with wings! I'm " << flightCount << std::endl;
		};
	}
};

#endif // !FLYBEHAVIOR_H
