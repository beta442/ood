#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include "CondimentDecoratorBase.h"

class Chocolate : public CondimentDecoratorBase
{
public:
	Chocolate(IBeveragePtr&& beverage, unsigned quantity = 1);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	unsigned m_quantity;
};

#endif // !CHOCOLATE_H
