#ifndef SWIMBEHAVIOR_H
#define SWIMBEHAVIOR_H

#include "pch.h"

static const std::function<void()> swimBehavior{
	[]() {
		std::cout << "I'm swimming!" << std::endl;
	}
};

static const std::function<void()> noSwimBehavior{
	[]() {}
};

#endif // !SWIMBEHAVIOR_H
