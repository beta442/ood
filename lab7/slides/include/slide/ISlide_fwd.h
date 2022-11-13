#ifndef SLIDES_SLIDE_ISLIDE_FWD_H_
#define SLIDES_SLIDE_ISLIDE_FWD_H_

#include <memory>

namespace slide
{

class ISlide;

using ISlideRawPtr = ISlide*;
using ISlidePtr = std::unique_ptr<ISlide>;
using ISlideSharedPtr = std::shared_ptr<ISlide>;

} // namespace slide

#endif // !SLIDES_SLIDE_ISLIDE_FWD_H_
