#ifndef SLIDES_SLIDE_SHAPE_ISHAPE_FWD_H_
#define SLIDES_SLIDE_SHAPE_ISHAPE_FWD_H_

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

#endif // !SLIDES_SLIDE_SHAPE_ISHAPE_FWD_H_
