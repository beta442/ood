#ifndef COCONUTFLAKES_H
#define COCONUTFLAKES_H

#include "CondimentDecoratorBase.h"

class CoconutFlakes : public CondimentDecoratorBase
{
public:
	CoconutFlakes(IBeveragePtr&& beverage, unsigned mass);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	unsigned m_mass;
};

#endif // !COCONUTFLAKES_H
