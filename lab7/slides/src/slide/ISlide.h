#pragma once

#include "ISlide_fwd.h"
#include "common/color/RGBAColor.h"
#include "drawable/IDrawable.h"
#include "drawable/shape/shapes/IShapes.h"

namespace slide
{

class ISlide : public IDrawable
{
public:
	using IShapes = shape::IShapes;
	using RGBAColor = common::RGBAColor;

	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual IShapes& GetShapes() const = 0;

	virtual ~ISlide() = default;
};

} // namespace slide
