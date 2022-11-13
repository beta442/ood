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
}

void SFMLCanvas::BeginFill(RGBAColor color)
{
}

void SFMLCanvas::EndFill()
{
}

void SFMLCanvas::MoveTo(double x, double y)
{
}

void SFMLCanvas::LineTo(double x, double y)
{
}

void SFMLCanvas::DrawEllipse(double left, double top, double width, double height)
{
}

} // namespace canvas
