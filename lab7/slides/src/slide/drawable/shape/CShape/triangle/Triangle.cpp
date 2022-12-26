#include "pch.h"

#include "Triangle.h"

#include "slide/common/rect/Rect.h"

namespace slide
{

namespace shape
{

Triangle::Triangle(const PointD& p1, const PointD& p2, const PointD& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(slide::common::GetMaxRectFromPoints<double>(std::vector<PointD>{ p1, p2, p3 }),
		std::move(outlineStyle),
		std::move(fillStyle))
	, m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
{
}

Triangle::Triangle(PointD&& p1, PointD&& p2, PointD&& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(slide::common::GetMaxRectFromPoints<double>(std::vector<PointD>{ p1, p2, p3 }),
		std::move(outlineStyle),
		std::move(fillStyle))
	, m_p1(std::move(p1))
	, m_p2(std::move(p2))
	, m_p3(std::move(p3))
{
}

void Triangle::Draw(canvas::ICanvas& canvas)
{
	canvas.SetFillColor(GetFillStyle());
	canvas.SetLineColor(GetOutlineStyle());
	canvas.DrawTriangle(m_p1, m_p2, m_p3);
}

} // namespace shape

} // namespace slide
