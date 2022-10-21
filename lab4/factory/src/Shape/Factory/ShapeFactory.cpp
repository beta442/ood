#include "../../../include/pch.h"

#include <sstream>

#include "../../../include/Shapes/Factory/ShapeFactory.h"

#include "../../../include/Shapes/Ellipse.h"
#include "../../../include/Shapes/Rectangle.h"
#include "../../../include/Shapes/RegularPolygon.h"
#include "../../../include/Shapes/Triangle.h"
#include "../../../include/Shapes/ShapeType.hpp"

template <typename Point = Point>
ShapeSharedPtr CreateEllipse(Point&& p, Color color, std::istream& is)
{
	unsigned int verticalR{}, horizontalR{};

	is >> verticalR;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read ellipse's parameter.");
	}

	is >> horizontalR;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read ellipse's parameter.");
	}

	return std::make_shared<Ellipse>(std::forward<Point>(p), verticalR, horizontalR, color);
}

template <typename Point = Point>
ShapeSharedPtr CreateRectangle(Point&& p, Color color, std::istream& is)
{
	unsigned int width{}, height{};

	is >> width;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read rectangle's parameter.");
	}

	is >> height;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read rectangle's parameter.");
	}

	return std::make_shared<Rectangle>(std::forward<Point>(p), width, height, color);
}

template <typename Point = Point>
ShapeSharedPtr CreateRegularPolygon(Point&& p, Color color, std::istream& is)
{
	unsigned int radius{};
	size_t vertexCount{};

	is >> radius;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read regular-polygon's argument {radius}");
	}

	is >> vertexCount;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read regular-polygon's argument {vertexCount}");
	}

	return std::make_shared<RegularPolygon>(p, radius, vertexCount, color);
}

template <typename Point = Point>
ShapeSharedPtr CreateTriangle(Point&& p, Color color, std::istream& is)
{
	std::vector<Point> points{ p };
	points.reserve(3);

	while (is.good())
	{
		is >> p;
		if (is.fail())
		{
			throw std::invalid_argument("Failed to read triangle's argument {Point}");
		}

		points.emplace_back(std::move(p));
	}

	return std::make_shared<Triangle>(std::move(points), color);
}

ShapeSharedPtr MakeShape(ShapeType type, Color color, std::istream& is)
{
	Point p{};

	is >> p;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read shape's parameter {Point}.");
	}

	switch (type)
	{
	case ShapeType::ELLIPSE:
		return CreateEllipse(std::move(p), color, is);
	case ShapeType::RECTANGLE:
		return CreateRectangle(std::move(p), color, is);
	case ShapeType::REGULAR_POLYGON:
		return CreateRegularPolygon(std::move(p), color, is);
	case ShapeType::TRIANGLE:
		return CreateTriangle(std::move(p), color, is);
	}

	return nullptr;
}

constexpr auto FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG = "Failed to create shape. Not enough arguments in description";

ShapeSharedPtr ShapeFactory::CreateShape(const std::string& dscrp) const
{
	std::stringstream ss{ dscrp };
	if (ss.eof())
	{
		throw std::invalid_argument(FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG);
	}

	ShapeType shapeType = ShapeType::UNKNOWN;
	Color color = Color::UNKNOWN;

	ss >> shapeType;
	if (ss.eof())
	{
		throw std::invalid_argument(FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG);
	}
	if (ss.fail() || shapeType == ShapeType::UNKNOWN)
	{
		throw std::invalid_argument("Failed to read shape's type and create shape");
	}

	ss >> color;
	if (ss.eof())
	{
		throw std::invalid_argument(FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG);
	}
	if (ss.fail() || color == Color::UNKNOWN)
	{
		throw std::invalid_argument("Failed to read shape's color and create shape");
	}

	ShapeSharedPtr ptr = MakeShape(shapeType, color, ss);

	if (ptr == nullptr)
	{
		throw std::invalid_argument("Failed to create shape. No such shape");
	}

	return ptr;
}
