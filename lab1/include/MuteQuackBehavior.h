#ifndef MUTEQUACKBEHAVIOR_H
#define MUTEQUACKBEHAVIOR_H

#include "IQuackBehavior.h"

class MuteQuackBehavior : public IQuackBehavior
{
public:
	void Quack() final;
};

#endif // !MUTEQUACKBEHAVIOR_H
