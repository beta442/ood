#include "pch.h"

#include "modern_graphics_lib/ModernGraphicsRenderer.h"

namespace modern_graphics_lib
{

ModernGraphicsRenderer::ModernGraphicsRenderer(std::ostream& strm)
	: m_out(strm)
	, m_drawing(false)
{
}

ModernGraphicsRenderer::~ModernGraphicsRenderer()
{
	if (m_drawing)
	{
		EndDraw();
	}
}

void ModernGraphicsRenderer::BeginDraw()
{
	if (m_drawing)
	{
		throw std::logic_error("Drawing has already begun");
	}
	m_out << "<draw>" << std::endl;
	m_drawing = true;
}

void ModernGraphicsRenderer::DrawLine(const Point& start, const Point& end)
{
	if (!m_drawing)
	{
		throw std::logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
	}
	m_out << "<line fromX=\"" << start.x << "\" fromY=\"" << start.y << "\" toX =\"" << end.x << "\" toY=\"" << end.y << "\" />"
		  << std::endl;
}

void ModernGraphicsRenderer::EndDraw()
{
	if (!m_drawing)
	{
		throw std::logic_error("Drawing has not been started");
	}
	m_out << "</draw>" << std::endl;
	m_drawing = false;
}

} // namespace modern_graphics_lib
