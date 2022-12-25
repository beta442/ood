#pragma once

#include <memory>

#include <SFML/Graphics/RenderTarget.hpp>

#include "canvas/ICanvas.h"

namespace canvas
{

class SFMLCanvas final : public ICanvas
{
public:
	using RenderTarget = std::unique_ptr<sf::RenderTarget>;

	SFMLCanvas(RenderTarget&& sfmlWindow);

	void SetLineColor(RGBAColor color) override;
	void BeginFill(RGBAColor color) override;
	void EndFill() override;
	void MoveTo(double x, double y) override;
	void LineTo(double x, double y) override;
	void DrawEllipse(double left, double top, double width, double height) override;

private:
	RenderTarget m_sfmlWindow;
};

} // namespace canvas
