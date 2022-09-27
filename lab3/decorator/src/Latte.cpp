#include "../include/pch.h"

#include "../include/Latte.h"

constexpr auto LATTE_COST = 90.;

Latte::Latte(const std::string& description)
	: BeverageImpl(description)
{
}

double Latte::GetCost() const
{
	return LATTE_COST;
}
