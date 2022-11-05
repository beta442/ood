#include "pch.h"

#include "shape_drawing_lib/Rectangle.h"

namespace shape_drawing_lib
{

Rectangle::Rectangle(const Point& leftTop, int width, int height, Color color)
	: m_leftTop(leftTop)
	, m_rightBottom()
	, m_width(width)
	, m_height(height)
	, m_color(color)
{
	if (m_width < 0 || m_height < 0)
	{
		throw std::invalid_argument("Failed to create rectangle. Given sides are negative");
	}

	m_rightBottom.x = m_leftTop.x + width;
	m_rightBottom.y = m_leftTop.y + height;
}

void Rectangle::Draw(const Canvas& canvas) const
{
	auto rightTop = Point{ m_rightBottom.x, m_leftTop.y };
	auto leftBottom = Point{ m_leftTop.x, m_rightBottom.y };

	canvas->SetColor(m_color);

	canvas->MoveTo(m_leftTop.x, m_leftTop.y);

	canvas->LineTo(rightTop.x, rightTop.y);
	canvas->LineTo(m_rightBottom.x, m_rightBottom.y);
	canvas->LineTo(leftBottom.x, leftBottom.y);
	canvas->LineTo(m_leftTop.x, m_leftTop.y);
}

} // namespace shape_drawing_lib
