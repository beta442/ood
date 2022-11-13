#include "pch.h"

#include "slides_common.h"

namespace slide
{

void TryCheckRectD(const RectD& rect)
{
	if (rect.height < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: height is negative");
	}

	if (rect.width < 0)
	{
		throw std::invalid_argument("Invalid rectangle was given: width is negative");
	}
}

} // namespace slide
