#ifndef ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_FWD_H_
#define ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_FWD_H_

#include <memory>

namespace graphics_lib
{

class ICanvas;

using ICanvasRawPtr = ICanvas*;

using ICanvasPtr = std::unique_ptr<ICanvas>;
using ICanvasSharedPtr = std::shared_ptr<ICanvas>;

} // namespace graphics_lib

#endif // !ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_FWD_H_
