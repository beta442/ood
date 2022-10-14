#ifndef SHAPES_POINT_HPP_
#define SHAPES_POINT_HPP_

#include <cmath>
#include <istream>

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

inline std::istream& operator>>(std::istream& lhs, Point& rhs)
{
	if (!std::istream::sentry(lhs))
	{
		return lhs;
	}

	double x{}, y{};

	lhs >> x;
	if (lhs.fail())
	{
		return lhs;
	}

	lhs >> y;
	if (lhs.fail())
	{
		return lhs;
	}

	rhs.x = x;
	rhs.y = y;

	return lhs;
}

#endif // !SHAPES_POINT_HPP_
