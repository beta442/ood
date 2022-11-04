#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_COMMON_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_COMMON_H_

#include "graphics_lib/ICanvas.h"
#include "Point.hpp"

namespace shape_drawing_lib
{

void DrawLine(const graphics_lib::ICanvasSharedPtr& canvas, const Point& from, const Point& to);

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_COMMON_H_
