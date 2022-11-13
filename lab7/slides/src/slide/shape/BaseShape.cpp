#include "pch.h"

#include "slide/shape/BaseShape.h"

namespace slide
{

namespace shape
{

BaseShape::RectD BaseShape::GetFrame()
{
}

void BaseShape::SetFrame(const RectD& rect)
{
}

IStyle& BaseShape::GetOutlineStyle()
{
}

const IStyle& BaseShape::GetOutlineStyle() const
{
}

IStyle& BaseShape::GetFillStyle()
{
}

const IStyle& BaseShape::GetFillStyle() const
{
}

IGroupShapeSharedPtr BaseShape::GetGroup()
{
}

IGroupShapeConstSharedPtr BaseShape::GetGroup() const
{
}

} // namespace shape

} // namespace slide
