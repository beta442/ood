#ifndef SQUEAKBEHAVIOR_H
#define SQUEAKBEHAVIOR_H

#include "IQuackBehavior.h"

class SqueakBehavior : public IQuackBehavior
{
public:
	void Quack() final;
};

#endif // !SQUEAKBEHAVIOR_H
