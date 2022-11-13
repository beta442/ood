#include "pch.h"

#include "slide/shape/Triangle.h"

namespace slide
{

namespace shape
{

Triangle::Triangle(const RectD& rect)
	: MyBase(rect)
{
}

Triangle::Triangle(RectD&& rect)
	: MyBase(std::move(rect))
{
}

Triangle::Triangle(const RectD& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(rect, std::move(outlineStyle), std::move(fillStyle))
{
}

Triangle::Triangle(RectD&& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(std::move(rect), std::move(outlineStyle), std::move(fillStyle))
{
}

void Triangle::Draw(canvas::ICanvas& canvas)
{
}

} // namespace shape

} // namespace slide
