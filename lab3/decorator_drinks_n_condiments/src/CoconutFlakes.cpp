#include "../include/pch.h"

#include "../include/CoconutFlakes.h"

CoconutFlakes::CoconutFlakes(IBeveragePtr&& beverage, unsigned mass)
	: CondimentDecoratorBase(std::move(beverage))
	, m_mass(mass)
{
}

constexpr auto COCONUT_FLAKES_MASS_COST_MULTIPLIER = 1.;

double CoconutFlakes::GetCondimentCost() const
{
	return COCONUT_FLAKES_MASS_COST_MULTIPLIER * m_mass;
}

std::string CoconutFlakes::GetCondimentDescription() const
{
	return "Coconut flakes " + std::to_string(m_mass) + "g";
}
