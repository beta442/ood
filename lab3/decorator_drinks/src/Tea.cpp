#include "../include/pch.h"

#include "../include/Tea.h"

constexpr auto TEA_COST = 30.;

Tea::Tea(const std::string& description)
	: BeverageImpl(description)
{
}

double Tea::GetCost() const
{
	return TEA_COST;
}
