#include "../include/pch.h"

#include "../include/Latte.h"

constexpr auto LATTE_DESCRIPTION = "Latte";

constexpr auto DOUBLE_LATTE_MODIFIER_DESCRIPTION = "double";
constexpr auto STANDARD_LATTE_MODIFIER_DESCRIPTION = "standard";

constexpr auto DOUBLE_LATTE_COST = 130.;
constexpr auto STANDART_LATTE_COST = 90.;

Latte::Latte(LattePortionSize size)
	: BeverageImpl(LATTE_DESCRIPTION)
	, m_cost()
{
	switch (size)
	{
	case LattePortionSize::STANDARD:
		m_cost = STANDART_LATTE_COST;
		m_description = m_description + ' ' + STANDARD_LATTE_MODIFIER_DESCRIPTION;
		break;
	case LattePortionSize::DOUBLE:
		m_cost = DOUBLE_LATTE_COST;
		m_description = m_description + ' ' + DOUBLE_LATTE_MODIFIER_DESCRIPTION;
		break;
	}
}

double Latte::GetCost() const
{
	return m_cost;
}
