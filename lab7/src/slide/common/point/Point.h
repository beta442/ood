#pragma once

// clang-format off
namespace slide { namespace common
{
// clang-format on

template <typename T>
struct Point
{
	T x, y;

	T Distance(const Point& other) const;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
};

} // namespace common
} // namespace slide
