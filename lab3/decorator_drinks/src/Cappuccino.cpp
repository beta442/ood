#include "../include/pch.h"

#include "../include/Cappuccino.h"

constexpr auto CAPPUCCINO_COST = 80.;

Cappuccino::Cappuccino(const std::string& description)
	: BeverageImpl(description)
{
}

double Cappuccino::GetCost() const
{
	return CAPPUCCINO_COST;
}
