#ifndef SYRUP_H
#define SYRUP_H

#include "CondimentDecoratorBase.h"

enum class SyrupType
{
	Chocolate,
	Maple,
};

class Syrup : public CondimentDecoratorBase
{
public:
	Syrup(IBeveragePtr&& beverage, SyrupType syrupType);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	SyrupType m_syrupType;
};

#endif // !SYRUP_H
