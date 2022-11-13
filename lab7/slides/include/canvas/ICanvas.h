#ifndef SLIDES_CANVAS_ICANVAS_H_
#define SLIDES_CANVAS_ICANVAS_H_

#include "ICanvas_fwd.h"
#include "slides_common.h"

namespace canvas
{

class ICanvas
{
public:
	using RGBAColor = slide::RGBAColor;

	virtual void SetLineColor(RGBAColor color) = 0;
	virtual void BeginFill(RGBAColor color) = 0;
	virtual void EndFill() = 0;
	virtual void MoveTo(double x, double y) = 0;
	virtual void LineTo(double x, double y) = 0;
	virtual void DrawEllipse(double left, double top, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas

#endif // !SLIDES_CANVAS_ICANVAS_H_
