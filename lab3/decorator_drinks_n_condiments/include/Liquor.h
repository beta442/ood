#ifndef LIQUOR_H
#define LIQUOR_H

#include "CondimentDecoratorBase.h"

enum class LiquorType
{
	NUT	= 0,
	CHOCOLATE,
};

class Liquor : public CondimentDecoratorBase
{
public:
	Liquor(IBeveragePtr&& beverage, LiquorType type);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	LiquorType m_type;
};

#endif // !LIQUOR_H
