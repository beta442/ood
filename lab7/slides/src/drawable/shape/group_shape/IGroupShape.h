#pragma once

#include "../IShape.h"
#include "../shapes/IShapes.h"
#include "IGroupShape_fwd.h"

namespace drawable::shape
{

class IGroupShape : public IShape
	, public IShapes
{
public:
	virtual ~IGroupShape() = default;
};

} // namespace drawable::shape
