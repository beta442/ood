#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_TRIANGLE_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_TRIANGLE_H_

#include "graphics_lib/ICanvas.h"

#include "ICanvasDrawable.h"
#include "Point.hpp"
#include "common.h"

namespace shape_drawing_lib
{

class Triangle : public ICanvasDrawable
{
public:
	explicit Triangle() = default;
	explicit Triangle(const Point& p1, const Point& p2, const Point& p3, Color color = DEFAULT_COLOR);

	void Draw(const Canvas& canvas) const override;

private:
	Color m_color;
	Point m_p1, m_p2, m_p3;
};

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_TRIANGLE_H_
