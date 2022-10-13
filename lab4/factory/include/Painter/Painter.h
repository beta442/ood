#ifndef PAINTER_PAINTER_H_
#define PAINTER_PAINTER_H_

#include "../Canvas/ICanvas.h"
#include "../Draft/PictureDraft.h"

class Painter
{
public:
	Painter() = default;

	void DrawPicture(const PictureDraft& draft, const CanvasSharedPtr& canvas);
};

#endif // !PAINTER_PAINTER_H_
