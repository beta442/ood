#ifndef DANCENOWAY_H
#define DANCENOWAY_H

#include "IDanceBehavior.h"

class DanceNoWay : public IDanceBehavior
{
public:
	void Dance() final;
};

#endif // !DANCENOWAY_H
