#include "../include/pch.h"

#include "../include/Milkshake.h"

constexpr auto MILKSHAKE_COST = 80.;

Milkshake::Milkshake(const std::string& description)
	: BeverageImpl(description)
{
}

double Milkshake::GetCost() const
{
	return MILKSHAKE_COST;
}
