#pragma once

#include "slide/common/rect/RectD.h"

#include "../IDrawable.h"
#include "group_shape/IGroupShape_fwd.h"
#include "IShape_fwd.h"
#include "style/IStyle.h"

namespace slide
{

namespace shape
{

class IShape : public IDrawable
{
public:
	using RectD = common::RectD;

	virtual RectD GetFrame() const = 0;
	virtual void SetFrame(const RectD& rect) = 0;

	virtual IStyle& GetOutlineStyle() = 0;
	virtual const IStyle& GetOutlineStyle() const = 0;

	virtual IStyle& GetFillStyle() = 0;
	virtual const IStyle& GetFillStyle() const = 0;

	virtual IGroupShapeSharedPtr GetGroup() = 0;
	virtual IGroupShapeConstSharedPtr GetGroup() const = 0;

	virtual ~IShape() = default;
};

} // namespace shape

} // namespace slide

