#pragma once

#include "../point/Point.h"

// clang-format off
namespace slide { namespace common
{
// clang-format on

template <typename T>
struct Rect
{
	Rect() = default;
	Rect(T x, T y, T width, T height)
		: leftTop(x, y)
		, width(width)
		, height(height)
	{
		TryCheckRect(*this);
	}

	Point<T> leftTop;
	T width, height;
};

template <typename T>
static inline void TryCheckRect(const Rect<T>& rect)
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

template <typename T, typename Container>
static inline Rect<T> GetMaxRect(const Container& container)
{
	T minX{}, minY{}, maxX{}, maxY{};

	for (const auto& rect : container)
	{
		minX = std::min(minX, rect.leftTop.x);
		minY = std::min(minY, rect.leftTop.y);

		maxX = std::max(maxX, rect.leftTop.x + rect.width);
		maxY = std::max(maxY, rect.leftTop.y + rect.height);
	}

	return Rect<T>(minX, minY, minX + maxX, minY + maxY);
}

template <typename T, typename Container>
static inline Rect<T> GetMaxRectFromPoints(const Container& container)
{
	T minX{}, minY{}, maxX{}, maxY{};

	for (const Point<T>& point : container)
	{
		minX = std::min(minX, point.x);
		minY = std::min(minY, point.y);

		maxX = std::max(maxX, point.x);
		maxY = std::max(maxY, point.y);
	}

	return Rect<T>(minX, minY, minX + maxX, minY + maxY);
}

} // namespace common
} // namespace slide
