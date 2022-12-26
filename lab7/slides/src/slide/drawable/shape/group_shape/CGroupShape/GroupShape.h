#pragma once

#include <list>
#include <optional>

#include "../IGroupShape.h"

#include "../../style/CStyle/StyleComposite.h"

namespace slide
{

namespace shape
{

class GroupShape final : public IGroupShape
{
public:
	explicit GroupShape();

	const RectD& GetFrame() const override;
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

	void Draw(Canvas& canvas) override;

private:
	using ShapesContainer = std::list<IShapeSharedPtr>;
	using GorupRectD = std::optional<RectD>;

	mutable GorupRectD m_groupRect;

	ShapesContainer m_containerShapes;
	StyleComposite m_fillStyle, m_oulineStyle;
};

} // namespace shape

} // namespace slide
