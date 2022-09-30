#ifndef LATTE_H
#define LATTE_H

#include "BeverageImpl.h"

constexpr auto LATTE_DESCRIPTION = "Latte";

class Latte : public BeverageImpl
{
public:
	Latte(const std::string& description = LATTE_DESCRIPTION);

	double GetCost() const override;
};

#endif // !LATTE_H
