#ifndef ADAPTER_CLASS_APP_MODERN_GRAPHICS_LIB_ADAPTER_H_
#define ADAPTER_CLASS_APP_MODERN_GRAPHICS_LIB_ADAPTER_H_

#include <ostream>

#include "graphics_lib/ICanvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"
#include "modern_graphics_lib/Point.hpp"

namespace app
{

class ModernGraphicsRendererAdapter : public graphics_lib::ICanvas
	, public modern_graphics_lib::ModernGraphicsRenderer
{
public:
	ModernGraphicsRendererAdapter(std::ostream& os);

	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;

private:
	using Target = graphics_lib::ICanvas;
	using Adaptee = modern_graphics_lib::ModernGraphicsRenderer;

	modern_graphics_lib::Point m_beginPoint;
	bool m_drawing;
};

} // namespace app

#endif // !ADAPTER_CLASS_APP_MODERN_GRAPHICS_LIB_ADAPTER_H_
