#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <iostream>

constexpr auto quackBehavior{
	[]() {
		std::cout << "I'm quacking!" << std::endl;
	}
};

constexpr auto squeakBehavior{
	[]() {
		std::cout << "I'm squeaking!" << std::endl;
	}
};

constexpr auto muteBehavior{
	[]() {}
};

#endif // !QUACKBEHAVIOR_H
