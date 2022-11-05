#include "../include/ModernGraphicsRendererAdapter.h"

namespace app
{

ModernGraphicsRendererAdapter::ModernGraphicsRendererAdapter(std::ostream& os)
	: Adaptee(os)
	, m_beginPoint(0, 0)
	, m_drawing(false)
{
}

void ModernGraphicsRendererAdapter::MoveTo(int x, int y)
{
	BeginDraw();

	m_beginPoint.x = x;
	m_beginPoint.y = y;

	m_drawing = true;
}

void ModernGraphicsRendererAdapter::LineTo(int x, int y)
{
	using namespace modern_graphics_lib;

	if (!m_drawing)
	{
		MoveTo(m_beginPoint.x, m_beginPoint.y);
	}

	DrawLine(m_beginPoint, Point{ x, y });
	EndDraw();

	m_drawing = false;
}

} // namespace app
