#include "pch.h"

#include "GroupShape.h"

namespace slide
{

namespace shape
{

//RectD GroupShape::GetFrame()
//{
//}
//
//void GroupShape::SetFrame(const RectD& rect)
//{
//}
//
//IStyle& GroupShape::GetOutlineStyle()
//{
//}
//
//const IStyle& GroupShape::GetOutlineStyle() const
//{
//}

//IStyle& GroupShape::GetFillStyle()
//{
//	/*bool isStyleSameForEach = std::all_of(m_containerShapes.begin(), m_containerShapes.end(), [](auto& item) {
//		
//	});*/
//}

//const IStyle& GroupShape::GetFillStyle() const
//{
//}

IGroupShapeSharedPtr GroupShape::GetGroup()
{
	return IGroupShapeSharedPtr(this);
}

IGroupShapeConstSharedPtr GroupShape::GetGroup() const
{
	return IGroupShapeConstSharedPtr(this);
}

size_t GroupShape::GetShapesCount() const
{
	return m_containerShapes.size();
}

void GroupShape::InsertShape(const IShapeSharedPtr& shape, std::optional<size_t> position)
{
	auto index = (position.has_value()) ? *position : m_containerShapes.size();
	auto it = m_containerShapes.begin();
	std::advance(it, index);

	m_containerShapes.insert(it, shape);
}

const IShapeSharedPtr& GroupShape::GetShapeAtIndex(size_t index)
{
	if (index >= m_containerShapes.size())
	{
		throw std::invalid_argument("Failed to get shape at" + std::to_string(index) + " index");
	}
	auto it = m_containerShapes.begin();
	std::advance(it, index);

	return *it;
}

void GroupShape::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_containerShapes.size())
	{
		throw std::invalid_argument("Failed to remove shape at" + std::to_string(index) + " index");
	}

	auto it = m_containerShapes.begin();
	std::advance(it, index);

	m_containerShapes.erase(it);
}

} // namespace shape

} // namespace slide
