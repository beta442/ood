#include "pch.h"

#include "graphics_lib/Canvas.h"

namespace graphics_lib
{

void Canvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")" << std::endl;
}
void Canvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")" << std::endl;
}

} // namespace graphics_lib
