#include "canvas/SFMLCanvas.h"

namespace canvas
{

using namespace slides_common;

SFMLCanvas::SFMLCanvas(const SFMLWindowSharedPtr& sfmlWindow)
	: m_sfmlWindow(sfmlWindow)
{
}

void SFMLCanvas::SetLineColor(RGBAColor color)
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

void SFMLCanvas::BeginFill(RGBAColor color)
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

void SFMLCanvas::EndFill()
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

void SFMLCanvas::MoveTo(double x, double y)
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

void SFMLCanvas::LineTo(double x, double y)
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

void SFMLCanvas::DrawEllipse(double left, double top, double width, double height)
{
	if (auto window = m_sfmlWindow.lock())
	{
	}
}

} // namespace canvas
