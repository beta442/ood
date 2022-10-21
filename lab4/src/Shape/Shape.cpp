#include "../../include/pch.h"

#include "../../include/Shapes/Shape.h"

const Point& Shape::GetBasePoint() const noexcept
{
	return m_basePoint;
}

Color Shape::GetColor() const noexcept
{
	return m_color;
}
