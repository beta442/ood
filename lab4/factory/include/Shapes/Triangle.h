#ifndef SHAPES_TRIANGLE_H_
#define SHAPES_TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape
{
public:
	template <typename Point = Point>
	Triangle(Point&& v1, Point&& v2, Point&& v3, Color color)
		: Shape(std::forward<Point>(v1), color)
		, m_vertex2(std::forward<Point>(v2))
		, m_vertex3(std::forward<Point>(v3))
	{
	}

	const Point& GetVertex1() const noexcept;
	const Point& GetVertex2() const noexcept;
	const Point& GetVertex3() const noexcept;

	void Draw(ICanvas* canvas) const final;

private:
	Point m_vertex2, m_vertex3;
};

#endif // !SHAPES_TRIANGLE_H_
