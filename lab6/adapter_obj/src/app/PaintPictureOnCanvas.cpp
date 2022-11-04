#include "pch.h"

#include "app/PaintPictureOnCanvas.h"

#include "app/ModernGraphicsRendererAdapter.h"
#include "graphics_lib/Canvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"

#include "shape_drawing_lib/CanvasPainter.h"
#include "shape_drawing_lib/Rectangle.h"
#include "shape_drawing_lib/Triangle.h"

namespace app
{

void PaintPicture(shape_drawing_lib::CanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	ICanvasDrawableSharedPtr triangle = std::make_shared<Triangle>(Point{ 10, 15 }, Point{ 100, 200 }, Point{ 150, 250 });
	ICanvasDrawableSharedPtr rectangle = std::make_shared<Rectangle>(Point{ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::ICanvasPtr simpleCanvas = std::make_unique<graphics_lib::Canvas>();
	shape_drawing_lib::CanvasPainter painter(std::move(simpleCanvas));
	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::ModernGraphicsRenderer renderer(std::cout);
	graphics_lib::ICanvasPtr simpleCanvas = std::make_unique<ModernGraphicsRendererAdapter>(renderer);
	shape_drawing_lib::CanvasPainter painter(std::move(simpleCanvas));

	PaintPicture(painter);
}

} // namespace app
