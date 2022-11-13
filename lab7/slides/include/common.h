#ifndef SLIDES_COMMON_H_
#define SLIDES_COMMON_H_

#include <cstdint>

namespace slides_common
{

using RGBAColor = uint32_t;

template <typename T>
struct Rect
{
	T x, y;
	T widht, height;
};

} // namespace slides_common

#endif // !SLIDES_COMMON_H_
