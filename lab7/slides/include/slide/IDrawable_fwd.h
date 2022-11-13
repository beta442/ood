#ifndef SLIDES_SLIDE_IDRAWABLE_FWD_H_
#define SLIDES_SLIDE_IDRAWABLE_FWD_H_

#include <memory>

namespace slide
{

class IDrawable;

using IDrawableRawPtr = IDrawable*;
using IDrawablePtr = std::unique_ptr<IDrawable>;
using IDrawableSharedPtr = std::shared_ptr<IDrawable>;

} // namespace slide

#endif // !SLIDES_SLIDE_IDRAWABLE_FWD_H_
