#include "pch.h"

#include "Slide.h"

#include "../../shape/group_shape/CGroupShape/GroupShape.h"

namespace drawable::slide
{

Slide::Slide()
	: m_shapeGroup(std::move(shape::GroupShape::CreateUnique()))
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

} // namespace drawable::slide
