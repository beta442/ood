#include "../include/pch.h"

#include "../include/Cream.h"

Cream::Cream(IBeveragePtr&& beverage)
	: CondimentDecoratorBase(std::move(beverage))
{
}

constexpr auto CINNAMON_COST = 20.;

double Cream::GetCondimentCost() const
{
	return CINNAMON_COST;
}

constexpr auto CINNAMON_DESCRIPTION = "Cream";

std::string Cream::GetCondimentDescription() const
{
	return CINNAMON_DESCRIPTION;
}
