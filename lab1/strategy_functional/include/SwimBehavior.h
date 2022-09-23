#ifndef SWIMBEHAVIOR_H
#define SWIMBEHAVIOR_H

#include <iostream>

constexpr auto swimBehavior{
	[]() {
		std::cout << "I'm swimming!" << std::endl;
	}
};

constexpr auto noSwimBehavior{
	[]() {}
};

#endif // !SWIMBEHAVIOR_H
