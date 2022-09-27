#ifndef LEMON_H
#define LEMON_H

#include "CondimentDecoratorBase.h"

class Lemon : public CondimentDecoratorBase
{
public:
	Lemon(IBeveragePtr&& beverage, unsigned quantity = 1);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	unsigned m_quantity;
};

#endif // !LEMON_H
