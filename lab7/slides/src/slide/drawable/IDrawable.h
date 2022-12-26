#pragma once

#include "IDrawable_fwd.h"
#include "canvas/ICanvas.h"

namespace slide
{

class IDrawable
{
public:
	using Canvas = canvas::ICanvas;

	virtual void Draw(Canvas& canvas) = 0;

	virtual ~IDrawable() = default;
};

} // namespace slide
