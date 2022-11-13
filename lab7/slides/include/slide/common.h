#ifndef SLIDES_SLIDE_UTIL_H_
#define SLIDES_SLIDE_UTIL_H_

#include "..\common.h"
#include "shape/IStyle.h"

namespace slide
{

using RectD = slides_common::Rect<double>;

void TryCheckRectD(const RectD& rect);

namespace shape
{

void TryCheckStyle(const IStyle& style);

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_UTIL_H_
