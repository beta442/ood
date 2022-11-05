#include "pch.h"

#include "graphics_lib/Canvas.h"

namespace graphics_lib
{

void ChangeOStream(std::ostream& os, size_t width, unsigned char fillSymb, decltype(std::hex) iosBase)
{
	os << std::setw(width) << std::setfill(fillSymb) << iosBase;
}

void Canvas::SetColor(Color rgbColor)
{
	const auto savedFill = std::cout.fill();
	ChangeOStream(std::cout, 6, '0', std::hex);
	std::cout << "SetColor #" << rgbColor << std::endl;
	ChangeOStream(std::cout, 0, savedFill, std::dec);
}

void Canvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")" << std::endl;
}
void Canvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")" << std::endl;
}

} // namespace graphics_lib
