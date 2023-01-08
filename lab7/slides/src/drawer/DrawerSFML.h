#pragma once

#include <SFML/Graphics/RenderTarget.hpp>

#include "canvas/ICanvas.h"
#include "drawable/slide/ISlide.h"

namespace drawer
{

class DrawerSFML
{
public:
	using SlideSharedPtr = drawable::slide::ISlideSharedPtr;
	using RenderTarget = std::shared_ptr<sf::RenderTarget>;

	explicit DrawerSFML(const RenderTarget& sfmlRenderTarget, const SlideSharedPtr& slide);

	void SetSlide(const SlideSharedPtr& slide);
	void Draw();

private:
	using Canvas = canvas::ICanvasSharedPtr;

	SlideSharedPtr m_slide;
	Canvas m_sfmlCanvas;
};

} // namespace drawer
