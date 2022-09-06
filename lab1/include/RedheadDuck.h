#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"

class RedheadDuck : public Duck
{
public:
	RedheadDuck();
	void Display() const override;
};

#endif // !REDHEADDUCK_H
