#include "pch.h"

#include "Rectangle.h"

namespace slide
{

namespace shape
{

Rectangle::Rectangle(const RectD& rect)
	: MyBase(rect)
{
}

Rectangle::Rectangle(RectD&& rect)
	: MyBase(std::move(rect))
{
}

Rectangle::Rectangle(const RectD& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(rect, std::move(outlineStyle), std::move(fillStyle))
{
}

Rectangle::Rectangle(RectD&& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(std::move(rect), std::move(outlineStyle), std::move(fillStyle))
{
}

void Rectangle::Draw(Canvas& canvas)
{
	const auto& rect = GetFrame();
	const auto& fillStyle = GetFillStyle();
	const auto& outlineStyle = GetOutlineStyle();

	canvas.SetFillColor(fillStyle);
	canvas.SetLineColor(outlineStyle);

	canvas.DrawRectangle(rect.leftTop.x, rect.leftTop.y, rect.width, rect.height);
}

} // namespace shape

} // namespace slide
