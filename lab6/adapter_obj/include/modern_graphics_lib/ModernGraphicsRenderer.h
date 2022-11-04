#ifndef ADAPTER_OBJ_MODERN_GRAPHICS_LIB_MODERN_GRAPHICS_RENDERER_H_
#define ADAPTER_OBJ_MODERN_GRAPHICS_LIB_MODERN_GRAPHICS_RENDERER_H_

#include "Point.hpp"

#include <ostream>

namespace modern_graphics_lib
{

class ModernGraphicsRenderer
{
public:
	ModernGraphicsRenderer(std::ostream& strm);
	~ModernGraphicsRenderer();

	void BeginDraw();
	void DrawLine(const Point& start, const Point& end);
	void EndDraw();

private:
	std::ostream& m_out;
	bool m_drawing = false;
};

} // namespace modern_graphics_lib

#endif // !ADAPTER_OBJ_MODERN_GRAPHICS_LIB_MODERN_GRAPHICS_RENDERER_H_
