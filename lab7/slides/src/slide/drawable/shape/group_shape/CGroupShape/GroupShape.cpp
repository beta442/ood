#include "pch.h"

#include "GroupShape.h"

#include "../../style/CStyle/StyleComposite.h"
#include "../../style/enumerator/FillStyleEnumerator.hpp"
#include "../../style/enumerator/OutlineStyleEnumerator.hpp"

#include "slide/common/rect/Rect.h"

namespace slide
{

namespace shape
{

GroupShape::GroupShape()
	: m_groupRect()
	, m_containerShapes()
	, m_fillStyle(std::move(std::make_unique<FillStyleEnumerator<ShapesContainer>>(m_containerShapes)))
	, m_oulineStyle(std::move(std::make_unique<OutlineStyleEnumerator<ShapesContainer>>(m_containerShapes)))
{
}

const common::RectD& GroupShape::GetFrame() const
{
	if (m_groupRect.has_value())
	{
		return *m_groupRect;
	}

	std::vector<RectD> rects;
	rects.reserve(GetShapesCount());
	for (const auto& shape : m_containerShapes)
	{
		rects.push_back(shape->GetFrame());
	}

	auto maxRect = slide::common::GetMaxRect<double>(rects);

	m_groupRect = maxRect;
	return *m_groupRect;
}

void GroupShape::SetFrame(const RectD& rect)
{
	auto& currFrame = GetFrame();

	auto coefX = rect.width / currFrame.width;
	auto coefY = rect.height / currFrame.height;

	for (const auto& shape : m_containerShapes)
	{
		auto& shapeFrame = shape->GetFrame();
		auto distanceX = shapeFrame.leftTop.x - currFrame.leftTop.x;
		auto distanceY = shapeFrame.leftTop.y - currFrame.leftTop.y;

		RectD newShapeFrame = {
			rect.leftTop.x + distanceX * coefX,
			rect.leftTop.y + distanceY * coefY,
			shapeFrame.width * coefX,
			shapeFrame.height * coefY
		};

		shape->SetFrame(newShapeFrame);
	}

	m_groupRect = std::nullopt;
}

IStyle& GroupShape::GetOutlineStyle()
{
	return m_oulineStyle;
}

const IStyle& GroupShape::GetOutlineStyle() const
{
	return m_oulineStyle;
}

IStyle& GroupShape::GetFillStyle()
{
	return m_fillStyle;
}

const IStyle& GroupShape::GetFillStyle() const
{
	return m_fillStyle;
}

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
{// TODO: prevent self insert
	const auto index = (position.has_value())
		? std::min(*position, m_containerShapes.size())
		: m_containerShapes.size();

	auto it = m_containerShapes.begin();
	std::advance(it, index);

	m_containerShapes.insert(it, shape);
}

const IShapeSharedPtr& GroupShape::GetShapeAtIndex(size_t index)
{
	if (index >= m_containerShapes.size())
	{
		throw std::out_of_range("Failed to get shape at" + std::to_string(index) + " index. Index is out of range");
	}

	auto it = m_containerShapes.begin();
	std::advance(it, index);

	return *it;
}

void GroupShape::RemoveShapeAtIndex(size_t index)
{
	if (index >= m_containerShapes.size())
	{
		throw std::out_of_range("Failed to remove shape at" + std::to_string(index) + " index. Index is out of range");
	}

	auto it = m_containerShapes.begin();
	std::advance(it, index);

	m_containerShapes.erase(it);
}

void GroupShape::Draw(Canvas& canvas)
{
	for (auto& shape : m_containerShapes)
	{
		shape->Draw(canvas);
	}
}

} // namespace shape

} // namespace slide
