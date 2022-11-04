#include "app/PaintPictureOnCanvas.h"

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
	graphics_lib::ICanvasSharedPtr simpleCanvas = std::make_shared<graphics_lib::Canvas>();
	shape_drawing_lib::CanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}

} // namespace app
