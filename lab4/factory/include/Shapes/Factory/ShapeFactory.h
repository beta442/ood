#ifndef SHAPES_FACTORY_SHAPE_FACTORY_H_
#define SHAPES_FACTORY_SHAPE_FACTORY_H_

#include "IShapeFactory.h"

class ShapeFactory : public IShapeFactory
{
public:
	ShapeSharedPtr CreateShape(const std::string& dscrp) const override;
};

#endif // !SHAPES_FACTORY_SHAPE_FACTORY_H_
