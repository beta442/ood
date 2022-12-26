#pragma once

#include "../BaseShape.h"

namespace slide
{

namespace shape
{

class Triangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	Triangle() = default;
	Triangle(const PointD& p1, const PointD& p2, const PointD& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	Triangle(PointD&& p1, PointD&& p2, PointD&& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

	void Draw(canvas::ICanvas& canvas) final;

private:
	PointD m_p1, m_p2, m_p3;
};

} // namespace shape

} // namespace slide
