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

	void SetOutlineStyle(const IStyle& style) override;
	const IStyle& GetOutlineStyle() const override;

	void SetFillStyle(const IStyle& style) override;
	const IStyle& GetFillStyle() const override;

	IGroupShapeSharedPtr GetGroup() override;
	IGroupShapeConstSharedPtr GetGroup() const override;

protected:
	BaseShape() = default;
	BaseShape(const RectD& frame, const Style& outlineStyle, const Style& fillStyle);
	BaseShape(RectD&& frame, Style&& outlineStyle, Style&& fillStyle);

private:
	RectD m_frame;
	Style m_outlineStyle, m_fillStyle;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_
