#include "canvas/SFMLCanvas.h"

namespace canvas
{

SFMLCanvas::SFMLCanvas(RenderTarget&& sfmlWindow)
	: m_sfmlWindow(std::move(sfmlWindow))
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
