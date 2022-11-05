#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_FWD_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_FWD_H_

#include <memory>

namespace shape_drawing_lib
{

class ICanvasDrawable;

using ICanvasDrawableRawPtr = ICanvasDrawable*;

using ICanvasDrawablePtr = std::unique_ptr<ICanvasDrawable>;
using ICanvasDrawableSharedPtr = std::shared_ptr<ICanvasDrawable>;

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_ICANVAS_DRAWABLE_FWD_H_
