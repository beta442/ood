#ifndef SHAPES_ISHAPE_H_
#define SHAPES_ISHAPE_H_

#include "../Canvas/ICanvas.h"

#include "Point.hpp"
#include "Color.h"

class IShape
{
public:
	virtual void Draw(ICanvas* canvas) const = 0;
	virtual const Point& GetBasePoint() const noexcept = 0;
	virtual Color GetColor() const noexcept = 0;

	virtual ~IShape() = default;
};

#endif // !SHAPES_ISHAPE_H_
