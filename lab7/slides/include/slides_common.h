#ifndef SLIDES_SLIDES_COMMON_H_
#define SLIDES_SLIDES_COMMON_H_

#include <cmath>
#include <cstdint>

namespace slide
{

using RGBAColor = uint32_t;

template <typename T>
struct Point
{
	T x, y;

	T Distance(const Point& other) const
	{
		return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const
	{
		return !(*this == other);
	}
};

using PointD = Point<double>;

template <typename T>
struct Rect
{
	Point<T> leftTop;
	T width, height;
};

using RectD = Rect<double>;

void TryCheckRectD(const RectD& rect);

} // namespace slides_common

#endif // !SLIDES_SLIDES_COMMON_H_
