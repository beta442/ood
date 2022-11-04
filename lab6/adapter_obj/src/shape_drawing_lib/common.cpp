#include "shape_drawing_lib/common.h"

namespace shape_drawing_lib
{

void DrawLine(const graphics_lib::ICanvasSharedPtr& canvas, const Point& from, const Point& to)
{
	canvas->LineTo(from.x, from.y);
	canvas->MoveTo(to.x, to.y);
}

} // namespace shape_drawing_lib
