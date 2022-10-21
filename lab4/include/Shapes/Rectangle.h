#ifndef SHAPES_CONCRETE_SHAPES_RECTANGLE_H_
#define SHAPES_CONCRETE_SHAPES_RECTANGLE_H_

#include <stdexcept>

#include "Shape.h"

class Rectangle : public Shape
{
public:
	template <typename Point = Point>
	Rectangle(Point&& leftTop, unsigned int width, unsigned int height, Color color)
		: Shape(std::forward<Point>(leftTop), color)
		, m_rightBottom(leftTop.x + width, leftTop.y + height)
	{
	}

	const Point& GetLeftTop() const noexcept;
	const Point& GetRightBottom() const noexcept;

	void Draw(const ICanvasSharedPtr& canvas) const final;

private:
	Point m_rightBottom;
};

#endif // !SHAPES_CONCRETE_SHAPES_RECTANGLE_H_
