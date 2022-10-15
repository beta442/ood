#ifndef SHAPES_CONCRETE_SHAPES_TRIANGLE_H_
#define SHAPES_CONCRETE_SHAPES_TRIANGLE_H_

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

	template <typename Points>
	Triangle(Points&& points, Color color)
		: Shape(points.size() > 0 ? *points.begin() : Point{}, color)
		, m_vertex2()
		, m_vertex3()
	{
		if (points.size() < 3)
		{
			throw std::invalid_argument("Failed to construct triangle. Not enough points were given {3 required}");
		}

		m_vertex2 = *(++points.begin());
		m_vertex3 = *(++(++points.begin()));
	}

	const Point& GetVertex1() const noexcept;
	const Point& GetVertex2() const noexcept;
	const Point& GetVertex3() const noexcept;

	void Draw(const ICanvasSharedPtr& canvas) const final;

private:
	Point m_vertex2, m_vertex3;
};

#endif // !SHAPES_CONCRETE_SHAPES_TRIANGLE_H_
