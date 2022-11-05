#ifndef ADAPTER_OBJ_GRAPHICS_LIB_CANVAS_H_
#define ADAPTER_OBJ_GRAPHICS_LIB_CANVAS_H_

#include "ICanvas.h"

namespace graphics_lib
{

class Canvas : public ICanvas
{
public:
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};

} // namespace graphics_lib

#endif // !ADAPTER_OBJ_GRAPHICS_LIB_CANVAS_H_
