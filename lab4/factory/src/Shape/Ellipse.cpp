#include "../../include/Shapes/Ellipse.h"

const Point& Ellipse::GetCenter() const noexcept
{
	return GetBasePoint();
}

double Ellipse::GetVerticalRadius() const noexcept
{
	return m_verticalR;
}

double Ellipse::GetHorizontalRadius() const noexcept
{
	return m_horizontalR;
}

void Ellipse::Draw(ICanvas* canvas) const
{
}
