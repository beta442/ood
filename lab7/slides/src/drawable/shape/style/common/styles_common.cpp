#include "pch.h"

#include "styles_common.h"

namespace drawable::shape
{

void TryCheckStyle(const IStyle& style)
{
	bool hasEnabledStatus = style.IsEnabled().has_value();
	bool hasColor = style.GetColor().has_value();
	if (hasEnabledStatus && style.IsEnabled().value() && !hasColor)
	{
		throw std::logic_error("Style can't be enabled without color");
	}
	if (!hasEnabledStatus && hasColor)
	{
		throw std::logic_error("Style can't has color and be without enabled/disabled state");
	}
}

} // namespace drawable::shape
