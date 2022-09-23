#ifndef DANCEBEHAVIOR_H
#define DANCEBEHAVIOR_H

#include <iostream>

constexpr auto danceBehavior{
	[]() {
		std::cout << "I'm dancing" << std::endl;
	}
};

constexpr auto noDanceBehavior{
	[]() {}
};

#endif // !DANCEBEHAVIOR_H
