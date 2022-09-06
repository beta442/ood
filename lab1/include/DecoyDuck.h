#ifndef DECOYDUCK_H
#define DECOYDUCK_H

#include "Duck.h"

class DecoyDuck : public Duck
{
public:
	DecoyDuck();
	void Display() const override;
};

#endif // !DECOYDUCK_H
