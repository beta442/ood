#ifndef COFFEE_H
#define COFFEE_H

#include "BeverageImpl.h"

constexpr auto COFFE_DESCRIPTION = "Coffee";

class Coffee : public BeverageImpl
{
public:
	Coffee(const std::string& description = COFFE_DESCRIPTION);

	double GetCost() const override;
};

#endif // !COFFEE_H
