#ifndef SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_
#define SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_

#include "IShape.h"

namespace slide
{

namespace shape
{

class BaseShape : public IShape
{
public:
	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	IStyle& GetOutlineStyle() override;
	const IStyle& GetOutlineStyle() const override;

	IStyle& GetFillStyle() override;
	const IStyle& GetFillStyle() const override;

	IGroupShapeSharedPtr GetGroup() override;
	IGroupShapeConstSharedPtr GetGroup() const override;

protected:
	BaseShape() = default;

private:

};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_BASE_SHAPE_H_
