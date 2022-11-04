#ifndef ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_
#define ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_

#include "ICanvas_fwd.h"

namespace graphics_lib
{

class ICanvas
{
public:
	virtual void MoveTo(int x, int y) = 0;
	virtual void LineTo(int x, int y) = 0;

	virtual ~ICanvas() = default;
};

} // namespace graphics_lib

#endif // !ADAPTER_OBJ_GRAPHICS_LIB_ICANVAS_H_
