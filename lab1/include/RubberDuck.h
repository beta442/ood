#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"

class RubberDuck : public Duck
{
public:
	RubberDuck();
	void Display() const override;
};

#endif // !RUBBERDUCK_H
