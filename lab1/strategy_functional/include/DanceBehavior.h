#ifndef DANCEBEHAVIOR_H
#define DANCEBEHAVIOR_H

#include "pch.h"

static const std::function<void()> danceBehavior{
	[]() {
		std::cout << "I'm dancing" << std::endl;
	}
};

static const std::function<void()> noDanceBehavior{
	[]() {}
};

#endif // !DANCEBEHAVIOR_H
