#include "../../include/Shapes/Ellipse.h"

const Point& Ellipse::GetCenter() const noexcept
{
	return GetBasePoint();
}

unsigned int Ellipse::GetVerticalRadius() const
{
	return m_verticalR;
}

unsigned int Ellipse::GetHorizontalRadius() const
{
	return m_horizontalR;
}

void Ellipse::Draw(const ICanvasSharedPtr& canvas) const
{
	canvas->SetColor(GetColor());
	canvas->DrawEllipse(GetCenter(), GetVerticalRadius(), GetHorizontalRadius());
}
