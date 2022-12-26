#include "pch.h"

#include "Slide.h"

#include "../drawable/shape/group_shape/CGroupShape/GroupShape.h"

namespace slide
{

Slide::Slide()
	: m_shapeGroup(std::move(
		std::make_unique<shape::GroupShape>()
	))
{
}

double Slide::GetWidth() const
{
	return m_shapeGroup->GetFrame().width;
}

double Slide::GetHeight() const
{
	return m_shapeGroup->GetFrame().height;
}

Slide::IShapes& Slide::GetShapes() const
{
	return *m_shapeGroup;
}

void Slide::Draw(canvas::ICanvas& canvas)
{
	m_shapeGroup->Draw(canvas);
}

} // namespace slide
