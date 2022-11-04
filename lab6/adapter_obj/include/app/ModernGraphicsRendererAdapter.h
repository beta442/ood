#ifndef ADAPTER_OBJ_APP_MODERN_GRAPHICS_RENDERER_ADAPTER_H_
#define ADAPTER_OBJ_APP_MODERN_GRAPHICS_RENDERER_ADAPTER_H_

#include "graphics_lib/ICanvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"
#include "modern_graphics_lib/Point.hpp"

namespace app
{

class ModernGraphicsRendererAdapter : public graphics_lib::ICanvas
{
public:
	using Renderer = modern_graphics_lib::ModernGraphicsRenderer;

	ModernGraphicsRendererAdapter(Renderer& renderer);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	Renderer& m_adaptee;
	modern_graphics_lib::Point m_beginPoint;
};

} // namespace app

#endif // !ADAPTER_OBJ_APP_MODERN_GRAPHICS_RENDERER_ADAPTER_H_
