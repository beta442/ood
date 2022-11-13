#include "slide/shape/Rectangle.h"

namespace slide
{

namespace shape
{

Rectangle::Rectangle(const RectD& rect, const Style& outlineStyle, const Style& fillStyle)
	: MyBase(rect, outlineStyle, fillStyle)
{
}

Rectangle::Rectangle(RectD&& rect, Style&& outlineStyle, Style&& fillStyle)
	: MyBase(std::move(rect), std::move(outlineStyle), std::move(fillStyle))
{
}

void Rectangle::Draw(canvas::ICanvas& canvas)
{
}

} // namespace shape

} // namespace slide
