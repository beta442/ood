#ifndef CAPPUCCINO_H
#define CAPPUCCINO_H

#include "BeverageImpl.h"

constexpr auto CAPPUCCINO_DESCRIPTION = "Cappuccino";

class Cappuccino : public BeverageImpl
{
public:
	Cappuccino(const std::string& description = CAPPUCCINO_DESCRIPTION);

	double GetCost() const override;
};

#endif // !CAPPUCCINO_H
