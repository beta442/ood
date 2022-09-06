#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"

class MallardDuck : public Duck
{
public:
	MallardDuck();

	void Display() const override;
};

#endif // !MALLARDDUCK_H
