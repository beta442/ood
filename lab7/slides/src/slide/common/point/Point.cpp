#include "pch.h"

#include "Point.h"

// clang-format off
namespace slide { namespace common
{
// clang-format on

template <typename T>
T Point<T>::Distance(const Point& other) const
{
	return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

template <typename T>
bool Point<T>::operator==(const Point& other) const
{
	return x == other.x && y == other.y;
}

template <typename T>
bool Point<T>::operator!=(const Point& other) const
{
	return !(*this == other);
}

} // namespace common
} // namespace slide
