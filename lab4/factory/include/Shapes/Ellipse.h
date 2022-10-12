#ifndef SHAPES_ELLIPSE_H_
#define SHAPES_ELLIPSE_H_

#include <stdexcept>

#include "Shape.h"

class Ellipse : public Shape
{
public:
	template <typename Point = Point>
	Ellipse(Point&& basePoint, double verticalR, double horizontalR, Color color)
		: Shape(std::forward<Point>(basePoint), color)
		, m_verticalR(verticalR)
		, m_horizontalR(horizontalR)
	{
		if (m_verticalR < 0 || m_horizontalR < 0)
		{
			throw std::invalid_argument("Failed to construct ellipse. Negative arguments were given");
		}
	}

	const Point& GetCenter() const noexcept;
	double GetVerticalRadius() const noexcept;
	double GetHorizontalRadius() const noexcept;

	void Draw(ICanvas* canvas) const final;

private:
	double m_verticalR, m_horizontalR;
};

#endif // !SHAPES_ELLIPSE_H_
