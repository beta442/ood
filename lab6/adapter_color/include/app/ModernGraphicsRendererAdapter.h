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
	using Color = graphics_lib::Color;
	using RGBAColor = modern_graphics_lib::RGBAColor;

	ModernGraphicsRendererAdapter(Renderer& renderer);

	void SetColor(Color rgbColor) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	Renderer& m_adaptee;
	RGBAColor m_rgbaColor;
	modern_graphics_lib::Point m_beginPoint;
	bool m_drawing;
};

} // namespace app

#endif // !ADAPTER_OBJ_APP_MODERN_GRAPHICS_RENDERER_ADAPTER_H_
