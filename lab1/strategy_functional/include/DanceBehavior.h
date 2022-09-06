#ifndef DANCEBEHAVIOR_H
#define DANCEBEHAVIOR_H

#include "pch.h"

const std::function<void()> danceBehavior{
	[]() {
		std::cout << "I'm dancing" << std::endl;
	}
};

const std::function<void()> noDanceBehavior{
	[]() {}
};

#endif // !DANCEBEHAVIOR_H
