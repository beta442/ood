#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include "pch.h"

static const std::function<void()> quackBehavior{
	[]() {
		std::cout << "I'm quacking!" << std::endl;
	}
};

static const std::function<void()> squeakBehavior{
	[]() {
		std::cout << "I'm squeaking!" << std::endl;
	}
};

const std::function<void()> muteBehavior{
	[]() {}
};

#endif // !QUACKBEHAVIOR_H
