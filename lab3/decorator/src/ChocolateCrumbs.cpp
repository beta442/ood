#include "../include/pch.h"

#include "../include/ChocolateCrumbs.h"

ChocolateCrumbs::ChocolateCrumbs(IBeveragePtr&& beverage, unsigned mass)
	: CondimentDecoratorBase(std::move(beverage))
	, m_mass(mass)
{
}

constexpr auto CHOCOLATE_CRUMBS_MASS_COST_MULTIPLIER = 2.;

double ChocolateCrumbs::GetCondimentCost() const
{
	return CHOCOLATE_CRUMBS_MASS_COST_MULTIPLIER * m_mass;
}

std::string ChocolateCrumbs::GetCondimentDescription() const
{
	return "Chocolate crumbs " + std::to_string(m_mass) + "g";
}
