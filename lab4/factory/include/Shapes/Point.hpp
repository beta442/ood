#ifndef SHAPES_POINT_HPP_
#define SHAPES_POINT_HPP_

#include <cmath>

struct Point
{
	Point() = default;

	Point(double x, double y)
		: x(x)
		, y(y)
	{
	}

	double Distance(const Point& other) const noexcept
	{
		return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	Point operator+(const Point& other) const
	{
		return Point{ x + other.x, y + other.y };
	}

	Point& operator+=(const Point& other) noexcept
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	bool operator==(const Point& other) const noexcept
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const noexcept
	{
		return !(*this == other);
	}

	double x{}, y{};
};

#endif // !SHAPES_POINT_HPP_
