#include "../include/pch.h"

#include "../include/Syrup.h"

Syrup::Syrup(IBeveragePtr&& beverage, SyrupType syrupType)
	: CondimentDecoratorBase(std::move(beverage))
	, m_syrupType(syrupType)
{
}

const auto SYRUP_COST = 15.;

double Syrup::GetCondimentCost() const
{
	return SYRUP_COST;
}

constexpr auto CHOCOLATE_SYRUP_DESCRIPTION = "Chocolate";
constexpr auto MAPLE_SYRUP_DESCRIPTION = "Maple";
constexpr auto UNKNOWN_SYRUP_DESCRIPTION = "Unknown";

std::string Syrup::GetCondimentDescription() const
{
	return std::string((m_syrupType == SyrupType::Chocolate)
				   ? CHOCOLATE_SYRUP_DESCRIPTION
				   : (m_syrupType == SyrupType::Chocolate) ? MAPLE_SYRUP_DESCRIPTION
														   : UNKNOWN_SYRUP_DESCRIPTION)
		+ " syrup";
}
