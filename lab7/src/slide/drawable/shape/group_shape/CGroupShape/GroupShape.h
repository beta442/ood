#pragma once

#include <list>

#include "../IGroupShape.h"

namespace slide
{

namespace shape
{

class GroupShape final : public IGroupShape
{
public:
	RectD GetFrame() const override;
	void SetFrame(const RectD& rect) override;

	IStyle& GetOutlineStyle() override;
	const IStyle& GetOutlineStyle() const override;

	IStyle& GetFillStyle() override;
	const IStyle& GetFillStyle() const override;

	IGroupShapeSharedPtr GetGroup() override;
	IGroupShapeConstSharedPtr GetGroup() const override;

	size_t GetShapesCount() const override;
	void InsertShape(const IShapeSharedPtr& shape, std::optional<size_t> position = std::nullopt) override;
	const IShapeSharedPtr& GetShapeAtIndex(size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	using ShapesContainer = std::list<IShapeSharedPtr>;

	ShapesContainer m_containerShapes;
};

} // namespace shape

} // namespace slide
