#ifndef DANCEBEHAVIOR_H
#define DANCEBEHAVIOR_H

#include "IDanceBehavior.h"

class DanceBehavior : public IDanceBehavior
{
public:
	void Dance() final;
};

#endif // !DANCEBEHAVIOR_H
