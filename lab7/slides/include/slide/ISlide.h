#ifndef SLIDES_SLIDE_ISLIDE_H_
#define SLIDES_SLIDE_ISLIDE_H_

#include "IDrawable.h"
#include "ISlide_fwd.h"
#include "shape/IShapes.h"

namespace slide
{

class ISlide : public IDrawable
{
public:
	using RGBAColor = slides_common::RGBAColor;

	using IShapes = shape::IShapes;

	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual IShapes& GetShapes() const = 0;

	virtual RGBAColor GetBackgroundColor() const = 0;
	virtual void SetBackgroundColor(RGBAColor color) = 0;

	virtual ~ISlide() = default;
};

} // namespace slide

#endif // !SLIDES_SLIDE_ISLIDE_H_
