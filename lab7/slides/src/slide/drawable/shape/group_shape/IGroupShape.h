#pragma once

#include "IGroupShape_fwd.h"
#include "../IShape.h"
#include "../shapes/IShapes.h"

namespace slide
{

namespace shape
{

class IGroupShape : public IShape, public IShapes
{
public:
	virtual ~IGroupShape() = default;
};

} // namespace shape

} // namespace slide
