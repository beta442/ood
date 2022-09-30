#include "../include/pch.h"

#include "../include/Tea.h"

constexpr auto TEA_DESCRIPTION = "Tea";

constexpr auto BLACK_TEA_MODIFIER_DESCRIPTION = "black";
constexpr auto GREEN_TEA_MODIFIER_DESCRIPTION = "green";
constexpr auto OOLONG_TEA_MODIFIER_DESCRIPTION = "oolong";
constexpr auto WHITE_TEA_MODIFIER_DESCRIPTION = "white";

constexpr auto BLACK_TEA_COST = 30.;
constexpr auto GREEN_TEA_COST = 35.;
constexpr auto OOLONG_TEA_COST = 40.;
constexpr auto WHITE_TEA_COST = 35.;

Tea::Tea(TeaType type)
	: BeverageImpl(TEA_DESCRIPTION)
	, m_cost()
{
	switch (type)
	{
	case TeaType::BLACK:
		m_cost = BLACK_TEA_COST;
		m_description = m_description + ' ' + BLACK_TEA_MODIFIER_DESCRIPTION;
		break;
	case TeaType::GREEN:
		m_cost = GREEN_TEA_COST;
		m_description = m_description + ' ' + GREEN_TEA_MODIFIER_DESCRIPTION;
		break;
	case TeaType::OOLONG:
		m_cost = OOLONG_TEA_COST;
		m_description = m_description + ' ' + OOLONG_TEA_MODIFIER_DESCRIPTION;
		break;
	case TeaType::WHITE:
		m_cost = WHITE_TEA_COST;
		m_description = m_description + ' ' + WHITE_TEA_MODIFIER_DESCRIPTION;
		break;
	}
}

double Tea::GetCost() const
{
	return m_cost;
}
