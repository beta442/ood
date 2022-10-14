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
	Point res{};

	std::for_each(points.begin(), points.end(), [&res](const auto& p) noexcept {
		res += p;
	});

	auto pointsQuantity = points.size();

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
{// see explanation at https://stackoverflow.com/questions/25866309/find-if-a-set-of-points-can-form-a-regular-polygon-or-not
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
	angles.reserve(pointsQuantity);
	std::for_each(points.begin(), points.end(), [center, &angles](const auto& p) noexcept {
		angles.emplace_back(std::atan2(p.y - center.y, p.x - center.x));
	});
	std::sort(angles.begin(), angles.end(), std::less<double>());

	return std::all_of(angles.begin(), angles.end(),
		[anglesDifferenceMultiplier = 2. * M_PI / pointsQuantity, counter = 0](const auto& a) mutable noexcept {
			auto _1 = (-M_PI + counter * anglesDifferenceMultiplier);
			auto _2 = (-M_PI + ++counter * anglesDifferenceMultiplier);
			return ((_1 <= a) && (a < _2));
		});
}

#endif // !SHAPES_REGULAR_POLYGON_CHECKER_HPP_
