#ifndef CINNAMON_H
#define CINNAMON_H

#include "CondimentDecoratorBase.h"

class Cinnamon : public CondimentDecoratorBase
{
public:
	Cinnamon(IBeveragePtr&& beverage);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;
};

#endif // !CINNAMON_H
