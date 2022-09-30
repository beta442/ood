#include "../include/pch.h"

#include "../include/Milkshake.h"

constexpr auto MILKSHAKE_DESCRIPTION = "Milkshake";

constexpr auto SMALL_MILKSHAKE_DESCRIPTION = "small";
constexpr auto MEDIUM_MILKSHAKE_DESCRIPTION = "medium";
constexpr auto LARGE_MILKSHAKE_DESCRIPTION = "large";

constexpr auto SMALL_MILKSHAKE_COST = 50.;
constexpr auto MEDIUM_MILKSHAKE_COST = 60.;
constexpr auto LARGE_MILKSHAKE_COST = 80.;

Milkshake::Milkshake(MilkshakePortionSize size)
	: BeverageImpl(MILKSHAKE_DESCRIPTION)
	, m_cost()
{
	switch (size)
	{
	case MilkshakePortionSize::SMALL:
		m_cost = SMALL_MILKSHAKE_COST;
		m_description = m_description + ' ' + SMALL_MILKSHAKE_DESCRIPTION;
		break;
	case MilkshakePortionSize::MEDIUM:
		m_cost = MEDIUM_MILKSHAKE_COST;
		m_description = m_description + ' ' + MEDIUM_MILKSHAKE_DESCRIPTION;
		break;
	case MilkshakePortionSize::LARGE:
		m_cost = LARGE_MILKSHAKE_COST;
		m_description = m_description + ' ' + LARGE_MILKSHAKE_DESCRIPTION;
		break;
	default:
		break;
	}
}

double Milkshake::GetCost() const
{
	return m_cost;
}
