#ifndef SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_
#define SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_

#include "IShape.h"
#include "Style.h"

namespace slide
{

namespace shape
{

class BaseShape : public IShape
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

protected:
	BaseShape();
	BaseShape(const RectD& frame);
	BaseShape(RectD&& frame);
	BaseShape(const RectD& frame, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	BaseShape(RectD&& frame, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

private:
	RectD m_frame;
	IStylePtr m_outlineStyle, m_fillStyle;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_
