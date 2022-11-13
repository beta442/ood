#include "pch.h"

#include "slide/shape/BaseShape.h"

namespace slide
{

namespace shape
{

BaseShape::BaseShape()
	: m_frame()
	, m_fillStyle(std::make_unique<Style>())
	, m_outlineStyle(std::make_unique<Style>())
{
}

BaseShape::BaseShape(const RectD& frame)
	: BaseShape()
{
	TryCheckRectD(frame);
	m_frame = frame;
}

BaseShape::BaseShape(RectD&& frame)
	: BaseShape()
{
	TryCheckRectD(frame);
	m_frame = std::move(frame);
}

BaseShape::BaseShape(const RectD& frame, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: m_frame(frame)
	, m_outlineStyle(std::move(outlineStyle))
	, m_fillStyle(std::move(fillStyle))
{
	TryCheckRectD(m_frame);
	TryCheckStyle(*m_outlineStyle);
	TryCheckStyle(*m_fillStyle);
}

BaseShape::BaseShape(RectD&& frame, IStylePtr&& outlineStyle, IStylePtr&& fillStyle)
	: m_frame(std::move(frame))
	, m_outlineStyle(std::move(outlineStyle))
	, m_fillStyle(std::move(fillStyle))
{
	TryCheckRectD(m_frame);
	TryCheckStyle(*m_outlineStyle);
	TryCheckStyle(*m_fillStyle);
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

IStyle& BaseShape::GetOutlineStyle()
{
	return *m_outlineStyle;
}

const IStyle& BaseShape::GetOutlineStyle() const
{
	return *m_outlineStyle;
}

IStyle& BaseShape::GetFillStyle()
{
	return *m_fillStyle;
}

const IStyle& BaseShape::GetFillStyle() const
{
	return *m_fillStyle;
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
