#ifndef ADAPTER_OBJ_MODERN_GRAPHICS_LIB_POINT_HPP_
#define ADAPTER_OBJ_MODERN_GRAPHICS_LIB_POINT_HPP_

namespace modern_graphics_lib
{

class Point
{
public:
	explicit Point(int x, int y)
		: x(x)
		, y(y)
	{
	}

	int x, y;
};

} // namespace modern_graphics_lib

#endif // !ADAPTER_OBJ_MODERN_GRAPHICS_LIB_POINT_HPP_
