#include "../include/pch.h"

#include "../include/IceCube.h"

IceCube::IceCube(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type)
	: CondimentDecoratorBase(std::move(beverage))
	, m_quantity(quantity)
	, m_type(type)
{
}

double IceCube::GetCondimentCost() const
{
	return (m_type == IceCubeType::Dry ? 10 : 5) * m_quantity;
}

constexpr auto DRY_ICE_DESCRIPTION = "Dry";
constexpr auto WATER_ICE_DESCRIPTION = "Water";
constexpr auto UNKNOWN_ICE_DESCRIPTION = "Unknown";

std::string IceCube::GetCondimentDescription() const
{
	return std::string((m_type == IceCubeType::Dry)
				   ? DRY_ICE_DESCRIPTION
				   : (m_type == IceCubeType::Water) ? WATER_ICE_DESCRIPTION
													: UNKNOWN_ICE_DESCRIPTION)
		+ " ice cubes x" + std::to_string(m_quantity);
}
