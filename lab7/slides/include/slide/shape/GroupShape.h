#ifndef SLIDES_SLIDE_SHAPE_GROUP_SHAPE_H_
#define SLIDES_SLIDE_SHAPE_GROUP_SHAPE_H_

#include "IGroupShape.h"

namespace slide
{

namespace shape
{

class GroupShape final : public IGroupShape
{
public:
	RectD GetFrame() const override;
	void SetFrame(const RectD& rect) override;

	void SetOutlineStyle(const IStyle& style) override;
	const IStyle& GetOutlineStyle() const override;

	void SetFillStyle(const IStyle& style) override;
	const IStyle& GetFillStyle() const override;

	IGroupShapeSharedPtr GetGroup() override;
	IGroupShapeConstSharedPtr GetGroup() const override;

	size_t GetShapesCount() const override;
	void InsertShape(const IShapeSharedPtr& shape, std::optional<size_t> position = std::nullopt) override;
	const IShapeSharedPtr& GetShapeAtIndex(size_t index) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_GROUP_SHAPE_H_
