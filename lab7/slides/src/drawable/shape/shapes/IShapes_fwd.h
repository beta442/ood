#pragma once

#include <memory>

namespace slide
{

namespace shape
{

class IShapes;

using IShapesRawPtr = IShapes*;
using IShapesPtr = std::unique_ptr<IShapes>;
using IShapesSharedPtr = std::shared_ptr<IShapes>;

} // namespace shape

} // namespace slide
