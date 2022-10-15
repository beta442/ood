#ifndef SHAPES_CONCRETE_SHAPES_ELLIPSE_H_
#define SHAPES_CONCRETE_SHAPES_ELLIPSE_H_

#include <stdexcept>

#include "Shape.h"

class Ellipse : public Shape
{
public:
	template <typename Point = Point>
	Ellipse(Point&& basePoint, unsigned int verticalR, unsigned int horizontalR, Color color)
		: Shape(std::forward<Point>(basePoint), color)
		, m_verticalR(verticalR)
		, m_horizontalR(horizontalR)
	{
	}

	const Point& GetCenter() const noexcept;
	unsigned int GetVerticalRadius() const;
	unsigned int GetHorizontalRadius() const;

	void Draw(const ICanvasSharedPtr& canvas) const final;

private:
	unsigned int m_verticalR, m_horizontalR;
};

#endif // !SHAPES_CONCRETE_SHAPES_ELLIPSE_H_
