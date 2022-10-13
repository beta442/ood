#ifndef SHAPES_FACTORY_SHAPES_FACTORY_H_
#define SHAPES_FACTORY_SHAPES_FACTORY_H_

#include "IShapeFactory.h"

class ShapeFactory : public IShapeFactory
{
public:
	ShapeSharedPtr CreateShape(const std::string& description) const override;
};

#endif // !SHAPES_FACTORY_SHAPES_FACTORY_H_
