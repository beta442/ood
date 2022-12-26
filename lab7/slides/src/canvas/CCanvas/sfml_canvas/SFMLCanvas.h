#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "canvas/ICanvas.h"

namespace canvas
{

class SFMLCanvas final : public ICanvas
{
public:
	using RenderTarget = std::shared_ptr<sf::RenderTarget>;

	explicit SFMLCanvas(const RenderTarget& sfmlRenderTarger);

	void SetLineColor(const Style& color) override;
	void SetFillColor(const Style& color) override;

	void DrawEllipse(double xLeftTop, double yLeftTop, double width, double height) override;
	void DrawRectangle(double xLeftTop, double yLeftTop, double width, double height) override;
	void DrawTriangle(const PointD& p1, const PointD& p2, const PointD& p3) override;

private:
	RGBAColor m_fillColor, m_lineColor;

	RenderTarget m_sfmlWindow;
};

} // namespace canvas
