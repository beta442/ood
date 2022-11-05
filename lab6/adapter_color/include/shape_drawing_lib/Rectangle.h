#ifndef ADAPTER_OBJ_SHAPE_DRAWING_LIB_RECTANGLE_H_
#define ADAPTER_OBJ_SHAPE_DRAWING_LIB_RECTANGLE_H_

#include "graphics_lib/ICanvas.h"

#include "ICanvasDrawable.h"
#include "Point.hpp"
#include "common.h"

namespace shape_drawing_lib
{

class Rectangle : public ICanvasDrawable
{
public:
	explicit Rectangle() = default;
	explicit Rectangle(const Point& leftTop, int width, int height, Color color = DEFAULT_COLOR);

	void Draw(const Canvas& canvas) const override;

private:
	int m_width, m_height;
	Color m_color;
	Point m_leftTop, m_rightBottom;
};

} // namespace shape_drawing_lib

#endif // !ADAPTER_OBJ_SHAPE_DRAWING_LIB_RECTANGLE_H_
