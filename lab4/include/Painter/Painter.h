#ifndef PAINTER_PAINTER_H_
#define PAINTER_PAINTER_H_

#include "../Canvas/ICanvas.h"
#include "../Draft/PictureDraft.h"

class Painter
{
public:
	void DrawPicture(const PictureDraft& draft, const ICanvasSharedPtr& canvas);
};

#endif // !PAINTER_PAINTER_H_
