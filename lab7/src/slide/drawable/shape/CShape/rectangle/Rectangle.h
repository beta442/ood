#pragma once

#include "../BaseShape.h"

namespace slide
{

namespace shape
{

class Rectangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	Rectangle() = default;
	Rectangle(const RectD& rect);
	Rectangle(RectD&& rect);
	Rectangle(const RectD& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	Rectangle(RectD&& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

	void Draw(Canvas& canvas) final;
};

} // namespace shape

} // namespace slide
