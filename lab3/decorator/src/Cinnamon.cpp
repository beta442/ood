#include "../include/pch.h"

#include "../include/Cinnamon.h"

Cinnamon::Cinnamon(IBeveragePtr&& beverage)
	: CondimentDecoratorBase(std::move(beverage))
{
}

constexpr auto CINNAMON_COST = 20.;

double Cinnamon::GetCondimentCost() const
{
	return CINNAMON_COST;
}

constexpr auto CINNAMON_DESCRIPTION = "Cinnamon";

std::string Cinnamon::GetCondimentDescription() const
{
	return CINNAMON_DESCRIPTION;
}
