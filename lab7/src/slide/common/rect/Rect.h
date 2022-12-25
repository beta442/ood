#pragma once

#include "../point/Point.h"

// clang-format off
namespace slide { namespace common
{
// clang-format on

template <typename T>
struct Rect
{
	Point<T> leftTop;
	T width, height;
};

template <typename T>
void TryCheckRect(const Rect<T>& rect)
{
	if (rect.height < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: height is negative");
	}

	if (rect.width < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: width is negative");
	}
}

} // namespace common
} // namespace slide
