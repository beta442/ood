#include "../include/pch.h"

#include "../include/Cappuccino.h"

constexpr auto CAPPUCCINO_DESCRIPTION = "Cappuccino";

constexpr auto DOUBLE_CAPPUCCINO_MODIFIER_DESCRIPTION = "double";
constexpr auto STANDARD_CAPPUCCINO_MODIFIER_DESCRIPTION = "standard";

constexpr auto DOUBLE_CAPPUCCINO_COST = 120.;
constexpr auto STANDART_CAPPUCCINO_COST = 80.;

Cappuccino::Cappuccino(CappuccinoPortionSize size)
	: BeverageImpl(CAPPUCCINO_DESCRIPTION)
	, m_cost()
{
	switch (size)
	{
	case CappuccinoPortionSize::STANDART:
		m_cost = STANDART_CAPPUCCINO_COST;
		m_description = m_description + ' ' + STANDARD_CAPPUCCINO_MODIFIER_DESCRIPTION;
		break;
	case CappuccinoPortionSize::DOUBLE:
		m_cost = DOUBLE_CAPPUCCINO_COST;
		m_description = m_description + ' ' + DOUBLE_CAPPUCCINO_MODIFIER_DESCRIPTION;
		break;
	}
}

double Cappuccino::GetCost() const
{
	return m_cost;
}
