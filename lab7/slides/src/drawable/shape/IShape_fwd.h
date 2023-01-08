#pragma once

#include <memory>

namespace drawable::shape
{

class IShape;

using IShapeRawPtr = IShape*;
using IShapePtr = std::unique_ptr<IShape>;
using IShapeSharedPtr = std::shared_ptr<IShape>;

} // namespace drawable::shape
