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
	auto selfColor = GetColor(), otherColor = other.GetColor();

	//TODO: only enabled||disabled at the same time styles are equal?
	if (!selfColor.has_value() || !otherColor.has_value())
	{
		return false;
	}
	return selfColor.value() == otherColor.value();
}

} // namespace shape

} // namespace slide
