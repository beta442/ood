#ifndef FLYBEHAVIOR_H
#define FLYBEHAVIOR_H

#include <iostream>

constexpr auto flyWithWingsBehavior{
	[]() {
		std::cout << "I'm flying with wings!" << std::endl;
	}
};

constexpr auto noFlyBehavior{
	[]() {}
};

constexpr auto countedFlyBehavior{
	[flightCount = 0]() mutable noexcept {
		++flightCount;
		std::cout << "I'm flying with wings! I'm " << flightCount << std::endl;
	}
};

#endif // !FLYBEHAVIOR_H
