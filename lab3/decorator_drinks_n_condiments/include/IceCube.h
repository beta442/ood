#ifndef ICECUBE_H
#define ICECUBE_H

#include "CondimentDecoratorBase.h"

enum class IceCubeType
{
	Dry,
	Water,
};

class IceCube : public CondimentDecoratorBase
{
public:
	IceCube(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type = IceCubeType::Water);

protected:
	double GetCondimentCost() const override;
	std::string GetCondimentDescription() const override;

private:
	unsigned m_quantity;
	IceCubeType m_type;
};

#endif // !ICECUBE_H
