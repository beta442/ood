#include "pch.h"

#include "slide/shapes_common.h"

namespace slide
{

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
