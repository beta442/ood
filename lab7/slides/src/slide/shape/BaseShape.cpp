#include "pch.h"

#include "slide/shape/BaseShape.h"

namespace slide
{

namespace shape
{

BaseShape::BaseShape(const RectD& frame, const Style& outlineStyle, const Style& fillStyle)
	: m_frame(frame)
	, m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
{
	TryCheckRectD(m_frame);
	TryCheckStyle(m_outlineStyle);
	TryCheckStyle(m_fillStyle);
}

BaseShape::BaseShape(RectD&& frame, Style&& outlineStyle, Style&& fillStyle)
	: m_frame(std::move(frame))
	, m_outlineStyle(std::move(outlineStyle))
	, m_fillStyle(std::move(fillStyle))
{
	TryCheckRectD(m_frame);
	TryCheckStyle(m_outlineStyle);
	TryCheckStyle(m_fillStyle);
}

RectD BaseShape::GetFrame() const
{
	return m_frame;
}

void BaseShape::SetFrame(const RectD& rect)
{
	TryCheckRectD(rect);
	m_frame = rect;
}

void TryEmplaceStyle(Style& dst, const IStyle& src)
{
	TryCheckStyle(src);
	if (src.IsEnabled().has_value())
	{
		dst.Enable(src.IsEnabled().value());
	}
	if (src.GetColor().has_value())
	{
		dst.SetColor(src.GetColor().value());
	}
}

void BaseShape::SetOutlineStyle(const IStyle& style)
{
	TryEmplaceStyle(m_outlineStyle, style);
}

const IStyle& BaseShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

void BaseShape::SetFillStyle(const IStyle& style)
{
	TryEmplaceStyle(m_outlineStyle, style);
}

const IStyle& BaseShape::GetFillStyle() const
{
	return m_fillStyle;
}

IGroupShapeSharedPtr BaseShape::GetGroup()
{
	return nullptr;
}

IGroupShapeConstSharedPtr BaseShape::GetGroup() const
{
	return nullptr;
}

} // namespace shape

} // namespace slide
