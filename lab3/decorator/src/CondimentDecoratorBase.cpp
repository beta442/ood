#include "../include/pch.h"

#include "../include/CondimentDecoratorBase.h"

CondimentDecoratorBase::CondimentDecoratorBase(IBeveragePtr&& beverage)
	: m_beverage(move(beverage))
{
}

std::string CondimentDecoratorBase::GetDescription() const
{
	return m_beverage->GetDescription() + ", " + GetCondimentDescription();
}

double CondimentDecoratorBase::GetCost() const
{
	return m_beverage->GetCost() + GetCondimentCost();
}
