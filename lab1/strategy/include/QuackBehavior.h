#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include "IQuackBehavior.h"

class QuackBehavior : public IQuackBehavior
{
public:
	void Quack() final;
};

#endif // !QUACKBEHAVIOR_H
