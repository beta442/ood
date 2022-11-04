#include "pch.h"

#include "shape_drawing_lib/Rectangle.h"
#include "shape_drawing_lib/common.h"

namespace shape_drawing_lib
{

Rectangle::Rectangle(const Point& leftTop, int width, int height)
	: m_leftTop(leftTop)
	, m_rightBottom()
	, m_width(width)
	, m_height(height)
{
	if (m_width < 0 || m_height < 0)
	{
		throw std::invalid_argument("Failed to create rectangle. Given sides are negative");
	}

	m_rightBottom.x = m_leftTop.x + width;
	m_rightBottom.y = m_leftTop.y + height;
}

void Draw2Lines(const Rectangle::Canvas& canvas, const Point& from, const Point& to1, const Point& to2)
{
	DrawLine(canvas, from, to1);
	DrawLine(canvas, from, to2);
}

void Rectangle::Draw(const Canvas& canvas) const
{
	auto rightTop = Point{ m_rightBottom.x, m_leftTop.y };
	auto leftBottom = Point{ m_leftTop.x, m_rightBottom.y };

	Draw2Lines(canvas, m_leftTop, rightTop, leftBottom);
	Draw2Lines(canvas, m_rightBottom, rightTop, leftBottom);
}

} // namespace shape_drawing_lib
