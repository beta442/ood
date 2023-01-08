#include "pch.h"

#include "Triangle.h"

#include "../../../common/rect/Rect.h"

namespace drawable::shape
{

using drawable::common::GetMaxRectFromPoints;

Triangle::Triangle(const PointD& p1, const PointD& p2, const PointD& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(GetMaxRectFromPoints<double>(std::vector<PointD>{ p1, p2, p3 }),
		std::move(outlineStyle),
		std::move(fillStyle))
	, m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
{
}

Triangle::Triangle(PointD&& p1, PointD&& p2, PointD&& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: MyBase(GetMaxRectFromPoints<double>(std::vector<PointD>{ p1, p2, p3 }),
		std::move(outlineStyle),
		std::move(fillStyle))
	, m_p1(std::move(p1))
	, m_p2(std::move(p2))
	, m_p3(std::move(p3))
{
}

void Triangle::SetFrame(const RectD& rect)
{
	const auto frameBefore = MyBase::GetFrame();
	MyBase::SetFrame(rect);

	const auto coefX = rect.width / frameBefore.width, coefY = rect.height / frameBefore.height;

	m_p1.x *= coefX;
	m_p2.x *= coefX;
	m_p3.x *= coefX;

	m_p1.x += rect.leftTop.x;
	m_p2.x += rect.leftTop.x;
	m_p3.x += rect.leftTop.x;

	m_p1.y *= coefY;
	m_p2.y *= coefY;
	m_p3.y *= coefY;

	m_p1.y += rect.leftTop.y;
	m_p2.y += rect.leftTop.y;
	m_p3.y += rect.leftTop.y;
}

void Triangle::Draw(canvas::ICanvas& canvas)
{
	canvas.SetFillColor(GetFillStyle());
	canvas.SetLineColor(GetOutlineStyle());
	canvas.DrawTriangle(m_p1, m_p2, m_p3);
}

} // namespace drawable::shape
