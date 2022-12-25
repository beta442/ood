#pragma once

#include "ICanvas_fwd.h"

#include "../slide/common/color/RGBAColor.h"

namespace canvas
{

class ICanvas
{
public:
	using RGBAColor = slide::common::RGBAColor;

	virtual void SetLineColor(RGBAColor color) = 0;
	virtual void BeginFill(RGBAColor color) = 0;
	virtual void EndFill() = 0;
	virtual void MoveTo(double x, double y) = 0;
	virtual void LineTo(double x, double y) = 0;
	virtual void DrawEllipse(double left, double top, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas
