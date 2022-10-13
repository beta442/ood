#include "../../include/Shapes/Rectangle.h"

const Point& Rectangle::GetLeftTop() const noexcept
{
	return GetBasePoint();
}

const Point& Rectangle::GetRightBottom() const noexcept
{
	return m_rightBottom;
}

void Rectangle::Draw(ICanvas* canvas) const
{
}
