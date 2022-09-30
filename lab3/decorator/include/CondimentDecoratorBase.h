#ifndef CONDIMENTDECORATORBASE_H
#define CONDIMENTDECORATORBASE_H

#include "IBeverage.h"

class CondimentDecoratorBase : public IBeverage
{
public:
	std::string GetDescription() const override;
	double GetCost() const override;

protected:
	CondimentDecoratorBase(IBeveragePtr&& beverage);

	virtual std::string GetCondimentDescription() const = 0;
	virtual double GetCondimentCost() const = 0;

private:
	IBeveragePtr m_beverage;
};

#endif // !CONDIMENTDECORATORBASE_H
