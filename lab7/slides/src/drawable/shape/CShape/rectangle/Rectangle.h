#pragma once

#include "../BaseShape.h"

namespace drawable::shape
{

class Rectangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	explicit Rectangle() = default;
	explicit Rectangle(const RectD& rect);
	explicit Rectangle(RectD&& rect);
	explicit Rectangle(const RectD& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	explicit Rectangle(RectD&& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

	void Draw(Canvas& canvas) final;
};

} // namespace drawable::shape
