#include "../include/pch.h"

#include "../include/BeverageImpl.h"

BeverageImpl::BeverageImpl(const std::string& description)
	: m_description(description)
{
}

std::string BeverageImpl::GetDescription() const
{
	return m_description;
}
