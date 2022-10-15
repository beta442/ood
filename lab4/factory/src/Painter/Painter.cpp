#include "../../include/Painter/Painter.h"

void Painter::DrawPicture(const PictureDraft& draft, const ICanvasSharedPtr& canvas)
{
	for (auto& figure : draft)
	{
		figure->Draw(canvas);
	}
}
