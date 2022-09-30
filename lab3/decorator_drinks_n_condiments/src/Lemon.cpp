#include "../include/pch.h"

#include "../include/Lemon.h"

Lemon::Lemon(IBeveragePtr&& beverage, unsigned quantity)
	: CondimentDecoratorBase(std::move(beverage))
	, m_quantity(quantity)
{
}

constexpr auto LEMON_COST = 10.;

double Lemon::GetCondimentCost() const
{
	return LEMON_COST * m_quantity;
}

std::string Lemon::GetCondimentDescription() const
{
	return "Lemon x" + std::to_string(m_quantity);
}
