#include "pch.h"

#include "slide/common.h"

namespace slide
{

void TryCheckRectD(const RectD& rect)
{
	if (rect.height < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: height is negative");
	}

	if (rect.width < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: width is negative");
	}
}

namespace shape
{

void TryCheckStyle(const IStyle& style)
{
	bool hasEnabledStatus = style.IsEnabled().has_value();
	bool hasColor = style.GetColor().has_value();
	if (hasEnabledStatus && !hasColor)
	{
		throw std::logic_error("Style can't be enabled without color");
	}
	if (!hasEnabledStatus && hasColor)
	{
		throw std::logic_error("Style can't has color and be without enabled/disabled state");
	}
}

} // namespace shape

} // namespace slide
