#ifndef SLIDES_SLIDE_SHAPE_ISHAPE_H_
#define SLIDES_SLIDE_SHAPE_ISHAPE_H_

#include "common.h"

#include "../IDrawable.h"
#include "IGroupShape_fwd.h"
#include "IShape_fwd.h"
#include "IStyle.h"

namespace slide
{

namespace shape
{

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() const = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual void SetOutlineStyle(const IStyle& style) = 0;
	virtual const IStyle& GetOutlineStyle() const = 0;

	virtual void SetFillStyle(const IStyle& style) = 0;
	virtual const IStyle& GetFillStyle() const = 0;

	virtual IGroupShapeSharedPtr GetGroup() = 0;
	virtual IGroupShapeConstSharedPtr GetGroup() const = 0;

	virtual ~IShape() = default;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_ISHAPE_H_
