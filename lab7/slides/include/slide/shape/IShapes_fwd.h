#ifndef SLIDES_SLIDE_SHAPE_ISHAPES_FWD_H_
#define SLIDES_SLIDE_SHAPE_ISHAPES_FWD_H_

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

#endif // !SLIDES_SLIDE_SHAPE_ISHAPES_FWD_H_
