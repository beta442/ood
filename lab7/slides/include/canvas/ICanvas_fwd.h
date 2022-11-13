#ifndef SLIDES_CANVAS_ICANVAS_FWD_H_
#define SLIDES_CANVAS_ICANVAS_FWD_H_

#include <memory>

namespace canvas
{

class ICanvas;

using ICanvasRawPtr = ICanvas*;
using ICanvasPtr = std::unique_ptr<ICanvas>;
using ICanvasSharedPtr = std::shared_ptr<ICanvas>;

} // namespace canvas

#endif // !SLIDES_CANVAS_ICANVAS_FWD_H_
