#ifndef MILKSHAKE_H
#define MILKSHAKE_H

#include "BeverageImpl.h"

constexpr auto MILKSHAKE_DESCRIPTION = "Milkshake";

class Milkshake : public BeverageImpl
{
public:
	Milkshake(const std::string& description = MILKSHAKE_DESCRIPTION);

	double GetCost() const override;
};

#endif // !MILKSHAKE_H
