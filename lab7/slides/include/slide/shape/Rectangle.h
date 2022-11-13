#ifndef SLIDES_SLIDE_SHAPE_RECTANGLE_H_
#define SLIDES_SLIDE_SHAPE_RECTANGLE_H_

#include "BaseShape.h"

namespace slide
{

namespace shape
{

class Rectangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	Rectangle() = default;
	Rectangle(const RectD& rect, const Style& outlineStyle, const Style& fillStyle);
	Rectangle(RectD&& rect, Style&& outlineStyle, Style&& fillStyle);

	void Draw(canvas::ICanvas& canvas) final;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_RECTANGLE_H_
