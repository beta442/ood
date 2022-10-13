#ifndef CANVAS_ICANVAS_H_
#define CANVAS_ICANVAS_H_

#include <memory>

#include "../Shapes/Color.hpp"
#include "../Shapes/Point.hpp"

class ICanvas
{
public:
	virtual void SetColor(Color color) noexcept = 0;
	virtual void DrawLine(const Point& from, const Point& to) = 0;
	virtual void DrawEllipse(double l, double t, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

using CanvasSharedPtr = std::shared_ptr<ICanvas>;

#endif // !CANVAS_ICANVAS_H_
