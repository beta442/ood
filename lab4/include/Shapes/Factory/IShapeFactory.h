#ifndef SHAPES_FACTORY_ISHAPE_FACTORY_H_
#define SHAPES_FACTORY_ISHAPE_FACTORY_H_

#include <memory>
#include <string>

#include "../IShape.h"

class IShapeFactory
{
public:
	virtual ShapeSharedPtr CreateShape(const std::string& dscrp) const = 0;

	virtual ~IShapeFactory() = default;
};

using IShapeFactorySharedPtr = std::shared_ptr<IShapeFactory>;

#endif // !SHAPES_FACTORY_ISHAPE_FACTORY_H_
