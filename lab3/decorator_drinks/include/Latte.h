#ifndef LATTE_H
#define LATTE_H

#include "BeverageImpl.h"

enum class LattePortionSize
{
	STANDARD = 0,
	DOUBLE,
};

class Latte : public BeverageImpl
{
public:
	Latte(LattePortionSize size = LattePortionSize::STANDARD);

	double GetCost() const override;

private:
	double m_cost;
};

#endif // !LATTE_H
