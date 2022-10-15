#ifndef SHAPES_UTIL_REGULAR_POLYGON_VERTEXES_CREATOR_HPP_
#define SHAPES_UTIL_REGULAR_POLYGON_VERTEXES_CREATOR_HPP_

#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>
#include <stdexcept>

#include "../Point.hpp"

inline std::vector<Point> CreateRegularPolygonVertexes(const Point& center, unsigned int radius, size_t vertexCount)
{
	if (vertexCount < 3)
	{
		throw std::invalid_argument("Failed to create regular-polygon points. _3 must be greater than 3");
	}

	double angle = 0.;
	double addAngle = 2 * M_PI / vertexCount;
	std::vector<Point> res{};
	res.reserve(vertexCount);

	for (size_t i = 0; i < vertexCount; ++i)
	{
		res.emplace_back(Point{
			static_cast<int>(std::round(radius * std::cos(angle))) + center.x,
			static_cast<int>(std::round(radius * std::sin(angle))) + center.y });
		angle += addAngle;
	}

	return res;
}

#endif // !SHAPES_UTIL_REGULAR_POLYGON_VERTEXES_CREATOR_HPP_
