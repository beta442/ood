#pragma once

// clang-format off
namespace slide { namespace common
{
// clang-format on

template <typename T>
struct Point
{
	Point() = default;
	Point(T x, T y)
		: x(x)
		, y(y)
	{
	}

	T Distance(const Point& other) const;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	T x, y;
};

} // namespace common
} // namespace slide
