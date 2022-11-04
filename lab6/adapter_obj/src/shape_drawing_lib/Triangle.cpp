#include "shape_drawing_lib/Triangle.h"
#include "shape_drawing_lib/common.h"

namespace shape_drawing_lib
{

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
	: m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
{
}

void Triangle::Draw(const Canvas& canvas) const
{
	DrawLine(canvas, m_p1, m_p2);
	DrawLine(canvas, m_p2, m_p3);
}

} // namespace shape_drawing_lib
