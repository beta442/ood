#include "shape_drawing_lib/CanvasPainter.h"

namespace shape_drawing_lib
{

CanvasPainter::CanvasPainter(const Canvas& canvas)
	: m_canvas(canvas)
{
	if (m_canvas == nullptr)
	{
		throw std::invalid_argument("Failed to create CanvasPainter, invalid canvas was given");
	}
}

void CanvasPainter::Draw(const ICanvasDrawableSharedPtr& drawable)
{
	if (drawable == nullptr)
	{
		throw std::invalid_argument("Failed to draw drawable, invalid drawable was given");
	}

	drawable->Draw(m_canvas);
}

} // namespace shape_drawing_lib
