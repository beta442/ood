#ifndef SLIDES_CANVAS_ICANVAS_H_
#define SLIDES_CANVAS_ICANVAS_H_

#include "ICanvas_fwd.h"
#include "common.h"

namespace canvas
{

class ICanvas
{
public:
	virtual void SetLineColor(slides_common::RGBAColor color) = 0;
	virtual void BeginFill(slides_common::RGBAColor color) = 0;
	virtual void EndFill() = 0;
	virtual void MoveTo(double x, double y) = 0;
	virtual void LineTo(double x, double y) = 0;
	virtual void DrawEllipse(double left, double top, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas

#endif // !SLIDES_CANVAS_ICANVAS_H_
