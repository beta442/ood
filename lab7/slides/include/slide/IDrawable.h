#ifndef SLIDES_SLIDE_IDRAWABLE_H_
#define SLIDES_SLIDE_IDRAWABLE_H_

#include "IDrawable_fwd.h"
#include "canvas/ICanvas.h"

namespace slide
{

class IDrawable
{
public:
	virtual void Draw(canvas::ICanvas& canvas) = 0;

	virtual ~IDrawable() = default;
};

} // namespace slide

#endif // !SLIDES_SLIDE_IDRAWABLE_H_
