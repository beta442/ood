#include "../../include/Shapes/Rectangle.h"

const Point& Rectangle::GetLeftTop() const noexcept
{
	return GetBasePoint();
}

const Point& Rectangle::GetRightBottom() const noexcept
{
	return m_rightBottom;
}

void Rectangle::Draw(const ICanvasSharedPtr& canvas) const
{
	auto& leftTopP = GetLeftTop();
	auto& rightBottomP = GetRightBottom();

	auto rightTopP = Point{ rightBottomP.x, leftTopP.y };
	auto leftBottomP = Point{ leftTopP.x, rightBottomP.y };

	canvas->SetColor(GetColor());
	canvas->DrawRegularPolygon({
		leftTopP,
		rightTopP,
		rightBottomP,
		leftBottomP
	});
}
