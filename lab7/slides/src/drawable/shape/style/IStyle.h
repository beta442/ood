#pragma once

#include <optional>

#include "IStyle_fwd.h"
#include "../../common/color/RGBAColor.h"

namespace drawable::shape
{

class IStyle
{
public:
	using RGBAColor = common::RGBAColor;

	using BoolO = std::optional<bool>;
	using RGBAColorO = std::optional<RGBAColor>;

	virtual BoolO IsEnabled() const = 0;
	virtual void Enable(bool enable) = 0;

	virtual RGBAColorO GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};

} // namespace drawable::shape
