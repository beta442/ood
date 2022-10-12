#ifndef SHAPES_RECTANGLE_H_
#define SHAPES_RECTANGLE_H_

#include <stdexcept>

#include "Shape.h"

class Rectangle : public Shape
{
public:
	template <typename Point = Point>
	Rectangle(Point&& leftTop, double width, double height, Color color)
		: Shape(std::forward<Point>(leftTop), color)
		, m_rightBottom(leftTop.x + width, leftTop.y + height)
	{
		if (width < 0 || height < 0)
		{
			throw std::invalid_argument("Failed to construct rectangle. Negative arguments were given");
		}
	}

	void Draw(ICanvas* canvas) const final;

private:
	Point m_rightBottom;
};

#endif // !SHAPES_RECTANGLE_H_
