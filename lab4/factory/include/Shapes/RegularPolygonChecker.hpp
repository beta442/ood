#ifndef SHAPES_REGULAR_POLYGON_CHECKER_HPP_
#define SHAPES_REGULAR_POLYGON_CHECKER_HPP_

#define _USE_MATH_DEFINES
#include <math.h>

#include <algorithm>
#include <vector>

#include "Point.hpp"

template <typename Points>
Point GetCenterPointFromPoints(Points&& points)
{
	auto pointsQuantity = points.size();

	Point res{};

	std::for_each(points.begin(), points.end(), [&res](const auto& p) noexcept {
		res += p;
	});

	res.x /= pointsQuantity;
	res.y /= pointsQuantity;

	return res;
}

template <typename Points>
bool ArePointsOnSameDistanceWithCertainPoint(Points&& points, const Point& p)
{
	if (points.size() == 0)
	{
		return false;
	}

	auto distance = p.Distance(*points.begin());

	return std::all_of(points.begin(), points.end(), [distance, p](const auto& _p) noexcept {
		return p.Distance(_p) == distance;
	});
}

template <typename Points>
bool ArePointsRepresentRegularPolygon(Points&& points)
{
	auto pointsQuantity = points.size();
	if (pointsQuantity == 0)
	{
		return false;
	}

	Point center = GetCenterPointFromPoints(std::forward<Points>(points));

	if (!ArePointsOnSameDistanceWithCertainPoint(std::forward<Points>(points), center))
	{
		return false;
	}

	std::vector<double> angles{};
	angles.resize(pointsQuantity);
	std::for_each(points.begin(), points.end(), [counter = 0, center, &angles](const auto& p) mutable noexcept {
		angles[counter++] = std::atan2(p.y - center.y, p.x - center.x);
	});

	return std::all_of(angles.begin(), angles.end(),
		[anglesDifferenceMultiplier = 2. * M_PI / pointsQuantity, counter = 1](const auto& a) mutable noexcept {
			return (a >= -M_PI && a < (-M_PI + counter++ * anglesDifferenceMultiplier));
		});
}

#endif // !SHAPES_REGULAR_POLYGON_CHECKER_HPP_
