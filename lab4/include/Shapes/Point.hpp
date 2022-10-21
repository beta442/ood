#ifndef SHAPES_COMMON_POINT_HPP_
#define SHAPES_COMMON_POINT_HPP_

#include <cmath>
#include <istream>

struct Point
{
	int x{}, y{};

	Point() = default;

	Point(int x, int y)
		: x(x)
		, y(y)
	{
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
};

inline std::istream& operator>>(std::istream& lhs, Point& rhs)
{
	if (!std::istream::sentry(lhs))
	{
		return lhs;
	}

	int x{}, y{};

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

#endif // !SHAPES_COMMON_POINT_HPP_
