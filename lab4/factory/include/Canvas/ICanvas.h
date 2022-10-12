#ifndef CANVAS_ICANVAS_H_
#define CANVAS_ICANVAS_H_

#include "../Shapes/Color.h"
#include "../Shapes/Point.hpp"

class ICanvas
{
public:
	virtual void SetColor(Color color) noexcept = 0;
	virtual void DrawLine(const Point& from, const Point& to) = 0;
	virtual void DrawEllipse(double l, double t, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

#endif // !CANVAS_ICANVAS_H_
