#ifndef ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_
#define ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_

#include "ICanvas_fwd.h"

namespace graphics_lib
{

using Color = uint32_t;

class ICanvas
{
public:
	virtual void SetColor(Color rgbColor) = 0;
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;

	virtual ~ICanvas() = default;
};

} // namespace graphics_lib

#endif // !ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_
