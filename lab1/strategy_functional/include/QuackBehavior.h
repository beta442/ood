#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include "pch.h"

const std::function<void()> quackBehavior{
	[]() {
		std::cout << "I'm quacking!" << std::endl;
	}
};

const std::function<void()> squeakBehavior{
	[]() {
		std::cout << "I'm squeaking!" << std::endl;
	}
};

const std::function<void()> muteBehavior{
	[]() {}
};

#endif // !QUACKBEHAVIOR_H
