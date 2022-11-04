#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_CANVAS_PAINTER_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_CANVAS_PAINTER_H_

#include <stdexcept>

#include "ICanvasDrawable.h"
#include "graphics_lib/ICanvas.h"

namespace shape_drawing_lib
{

class CanvasPainter
{
public:
	using Canvas = graphics_lib::ICanvasSharedPtr;

	CanvasPainter(const Canvas& canvas);

	void Draw(const ICanvasDrawableSharedPtr& drawable);

private:
	Canvas m_canvas;
};

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_CANVAS_PAINTER_H_
