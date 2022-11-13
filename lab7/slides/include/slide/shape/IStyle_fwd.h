#ifndef SLIDES_SLIDE_SHAPE_ISTYLE_FWD_H_
#define SLIDES_SLIDE_SHAPE_ISTYLE_FWD_H_

#include <memory>

namespace slide
{

namespace shape
{

class IStyle;

using IStyleRawPtr = IStyle*;
using IStylePtr = std::unique_ptr<IStyle>;
using IStyleSharedPtr = std::shared_ptr<IStyle>;

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_ISTYLE_FWD_H_
