#ifndef SHAPES_CONCRETE_SHAPES_REGULAR_POLYGON_H_
#define SHAPES_CONCRETE_SHAPES_REGULAR_POLYGON_H_

#include <vector>

#include "Shape.h"
#include "Util/RegularPolygonVertexesCreator.hpp"

class RegularPolygon : public Shape
{
public:
	template <typename Point = Point>
	RegularPolygon(Point&& center, unsigned int radius, size_t vertexCount, Color color)
		: Shape(center, color)
		, m_points(std::move(CreateRegularPolygonVertexes(std::forward<Point>(center), radius, vertexCount)))
		, m_radius(radius)
	{
	}

	const Point& GetCenter() const noexcept;
	unsigned int GetRadius() const noexcept;
	size_t GetVertexCount() const;

	void Draw(const ICanvasSharedPtr& canvas) const final;

private:
	unsigned int m_radius;
	std::vector<Point> m_points;
};

#endif // !SHAPES_CONCRETE_SHAPES_REGULAR_POLYGON_H_
