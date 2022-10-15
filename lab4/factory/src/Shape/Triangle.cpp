#include "../../include/Shapes/Triangle.h"

const Point& Triangle::GetVertex1() const noexcept
{
	return GetBasePoint();
}

const Point& Triangle::GetVertex2() const noexcept
{
	return m_vertex2;
}

const Point& Triangle::GetVertex3() const noexcept
{
	return m_vertex3;
}

void Triangle::Draw(const ICanvasSharedPtr& canvas) const
{
	canvas->SetColor(GetColor());
	canvas->DrawRegularPolygon({
		GetVertex1(),
		GetVertex2(),
		GetVertex3()
	});
}
