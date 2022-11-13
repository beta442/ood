#ifndef SLIDES_SLIDE_SHAPE_TRIANGLE_H_
#define SLIDES_SLIDE_SHAPE_TRIANGLE_H_

#include "BaseShape.h"

namespace slide
{

namespace shape
{

class Triangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	Triangle() = default;
	Triangle(const RectD& rect);
	Triangle(RectD&& rect);
	Triangle(const RectD& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	Triangle(RectD&& rect, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

	void Draw(canvas::ICanvas& canvas) final;

private:
	PointD m_p1, m_p2, m_p3;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_TRIANGLE_H_
