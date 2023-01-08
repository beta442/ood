#pragma once

#include "../ISlide.h"
#include "../../shape/group_shape/IGroupShape.h"

namespace drawable::slide
{

class Slide : public ISlide
{
public:
	explicit Slide();

	double GetWidth() const override;
	double GetHeight() const override;

	IShapes& GetShapes() const override;

	void Draw(canvas::ICanvas& canvas) override;

private:
	using ShapeGroup = shape::IGroupShapePtr;

	ShapeGroup m_shapeGroup;
};

} // namespace drawable::slide
