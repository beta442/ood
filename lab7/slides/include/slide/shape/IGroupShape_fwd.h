#ifndef SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_FWD_H_
#define SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_FWD_H_

#include <memory>

namespace slide
{

namespace shape
{

class IGroupShape;

using IGroupShapeRawPtr = IGroupShape*;
using IGroupShapePtr = std::unique_ptr<IGroupShape>;
using IGroupShapeSharedPtr = std::shared_ptr<IGroupShape>;
using IGroupShapeConstSharedPtr = std::shared_ptr<const IGroupShape>;

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_FWD_H_
