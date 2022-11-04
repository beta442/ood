#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_H_

#include "ICanvasDrawable_fwd.h"
#include "graphics_lib/ICanvas.h"

namespace shape_drawing_lib
{

class ICanvasDrawable
{
public:
	using Canvas = graphics_lib::ICanvasPtr;

	virtual void Draw(const Canvas& canvas) const = 0;

	virtual ~ICanvasDrawable() = default;
};

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_H_
