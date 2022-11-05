#include "app/ModernGraphicsRendererAdapter.h"

namespace app
{

ModernGraphicsRendererAdapter::ModernGraphicsRendererAdapter(Renderer& renderer)
	: m_adaptee(renderer)
	, m_beginPoint(0, 0)
	, m_drawing(false)
	, m_rgbaColor(0, 0, 0, 1)
{
}

void ModernGraphicsRendererAdapter::SetColor(Color rgbColor)
{
	auto red = float(rgbColor & 0xFF) / 255;
	auto green = float((rgbColor >> 8) & 0xFF) / 255;
	auto blue = float((rgbColor >> 16) & 0xFF) / 255;

	m_rgbaColor = { red, green, blue, 1 };
}

void ModernGraphicsRendererAdapter::MoveTo(int x, int y)
{
	m_adaptee.BeginDraw();

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

	m_adaptee.DrawLine(m_beginPoint, Point{ x, y }, m_rgbaColor);
	m_adaptee.EndDraw();

	m_drawing = false;
}

} // namespace app
