#pragma once

#include "ICanvas_fwd.h"

#include "slide/drawable/shape/style/IStyle.h"
#include "slide/common/point/PointD.h"

namespace canvas
{

class ICanvas
{
public:
	using Style = slide::shape::IStyle;
	using RGBAColor = Style::RGBAColor;
	using PointD = slide::common::PointD;

	virtual void SetLineColor(const Style& color) = 0;
	virtual void SetFillColor(const Style& color) = 0;

	virtual void DrawRectangle(double xLeftTop, double yLeftTop, double width, double height) = 0;
	virtual void DrawEllipse(double xLeftTop, double yLeftTop, double width, double height) = 0;
	virtual void DrawTriangle(const PointD& p1, const PointD& p2, const PointD& p3) = 0;

	virtual ~ICanvas() = default;
};

} // namespace canvas
