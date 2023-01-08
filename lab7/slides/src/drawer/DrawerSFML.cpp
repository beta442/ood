#include "pch.h"

#include "DrawerSFML.h"

#include "canvas/CCanvas/sfml_canvas/SFMLCanvas.h"

namespace drawer
{

constexpr auto ERR_INSTATIATE_WITH_NULL_SLIDE = "Cant instantiate DrawerSFML with slide ptr that points at null";
constexpr auto ERR_SET_NULL_SLIDE = "Cant set DrawerSFML with slide ptr that points at null";

DrawerSFML::DrawerSFML(const RenderTarget& sfmlRenderTarget, const SlideSharedPtr& slide)
	: m_sfmlCanvas(std::move(
		std::make_shared<canvas::SFMLCanvas>(sfmlRenderTarget)))
	, m_slide(slide)
{
	if (m_slide.get() == nullptr)
	{
		throw std::domain_error(ERR_INSTATIATE_WITH_NULL_SLIDE);
	}
}

void DrawerSFML::SetSlide(const SlideSharedPtr& slide)
{
	if (slide.get() == nullptr)
	{
		throw std::runtime_error(ERR_SET_NULL_SLIDE);
	}

	m_slide = slide;
}

void DrawerSFML::Draw()
{
	m_slide->Draw(*m_sfmlCanvas);
}

} // namespace drawer
