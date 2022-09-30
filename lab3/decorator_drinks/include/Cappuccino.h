#ifndef CAPPUCCINO_H
#define CAPPUCCINO_H

#include "BeverageImpl.h"

enum class CappuccinoPortionSize
{
	STANDART = 0,
	DOUBLE,
};

class Cappuccino : public BeverageImpl
{
public:
	Cappuccino(CappuccinoPortionSize size = CappuccinoPortionSize::STANDART);

	double GetCost() const override;

private:
	double m_cost;
};

#endif // !CAPPUCCINO_H
