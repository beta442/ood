#ifndef SHAPES_FACTORY_ISHAPE_FACTORY_H_
#define SHAPES_FACTORY_ISHAPE_FACTORY_H_

#include <string>

#include "../IShape.h"

class IShapeFactory
{
public:
	virtual ShapeSharedPtr CreateShape(const std::string& description) const = 0;

	virtual ~IShapeFactory() = default;
};

#endif // !SHAPES_FACTORY_ISHAPE_FACTORY_H_
