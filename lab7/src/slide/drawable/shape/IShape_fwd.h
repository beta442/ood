#pragma once

#include <memory>

namespace slide
{

namespace shape
{

class IShape;

using IShapeRawPtr = IShape*;
using IShapePtr = std::unique_ptr<IShape>;
using IShapeSharedPtr = std::shared_ptr<IShape>;

} // namespace shape

} // namespace slide
