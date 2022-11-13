#include "slide/shape/Style.h"

namespace slide
{

namespace shape
{

Style::BoolO Style::IsEnabled() const
{
	return m_isEnabled;
}

void Style::Enable(bool enable)
{
	m_color.emplace(enable);
}

Style::RGBAColorO Style::GetColor() const
{
	return m_color;
}

void Style::SetColor(RGBAColor color)
{
	m_color.emplace(color);
}

} // namespace shape

} // namespace slide
