#ifndef SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_H_
#define SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_H_

#include "IGroupShape_fwd.h"
#include "IShape.h"
#include "IShapes.h"

namespace slide
{

namespace shape
{

class IGroupShape : public IShape, public IShapes
{
public:
	virtual ~IGroupShape() = default;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_IGROUP_SHAPE_H_
