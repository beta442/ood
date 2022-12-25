#include "pch.h"

#include "Style.h"

namespace slide
{

namespace shape
{

Style::Style(RGBAColor color)
	: m_isEnabled(true)
	, m_color(color)
{
}

Style::Style(RGBAColor color, bool enableOnInit)
	: m_isEnabled(enableOnInit)
	, m_color(color)
{
}

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

bool Style::operator==(const Style& other) const noexcept
{
	//TODO: only enabled or disabled at the same time styles are equal?
	if (!m_color.has_value() || !other.GetColor().has_value())
	{
		return false;
	}
	return *m_color == *other.GetColor();
}

} // namespace shape

} // namespace slide
