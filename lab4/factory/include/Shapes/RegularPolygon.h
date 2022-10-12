#ifndef SHAPES_REGULAR_POLYGON_H_
#define SHAPES_REGULAR_POLYGON_H_

#include <optional>
#include <stdexcept>
#include <vector>

#include "RegularPolygonChecker.hpp"
#include "Shape.h"

class RegularPolygon : public Shape
{
public:
	template <typename Points>
	RegularPolygon(Points&& points, Color color)
		: Shape((points.size() > 0) ? (*points.begin()) : Point{}, color)
	{
		if (ArePointsRepresentRegularPolygon(std::forward<Points>(points)) == false)
		{
			throw std::invalid_argument("Failed to construct Regular polygon with given points");
		}

		m_points = std::forward<Points>(points);
	}

	const Point& GetCenter() const;
	const double& GetRadius() const noexcept;

	void Draw(ICanvas* canvas) const final;

private:
	mutable std::optional<Point> m_center;
	mutable std::optional<double> m_radius;

	std::vector<Point> m_points;
};

#endif // !SHAPES_REGULAR_POLYGON_H_
