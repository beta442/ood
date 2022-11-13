#ifndef SLIDES_SLIDE_SHAPE_ISTYLE_H_
#define SLIDES_SLIDE_SHAPE_ISTYLE_H_

#include <optional>

#include "IStyle_fwd.h"
#include "common.h"

namespace slide
{

namespace shape
{

class IStyle
{
public:
	using BoolO = std::optional<bool>;

	using RGBAColor = slides_common::RGBAColor;
	using RGBAColorO = std::optional<RGBAColor>;

	virtual BoolO IsEnabled() const = 0;
	virtual void Enable(bool enable) = 0;

	virtual RGBAColorO GetColor() const = 0;
	virtual void SetColor(RGBAColor color) = 0;

	virtual ~IStyle() = default;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_ISTYLE_H_
