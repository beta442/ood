#ifndef CREAM_H
#define CREAM_H

#include "CondimentDecoratorBase.h"

class Cream : public CondimentDecoratorBase
{
public:
	Cream(IBeveragePtr&& beverage);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;
};

#endif // !CREAM_H
