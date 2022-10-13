#include "../../../include/Shapes/Factory/ShapeFactory.h"

#include "../../../include/Shapes/ShapeType.hpp"

#include <sstream>

constexpr std::string_view RECTANGLE_SHAPE_TYPE = "rectangle";
constexpr std::string_view TRIANGLE_SHAPE_TYPE = "triangle";
constexpr std::string_view ELLIPSE_SHAPE_TYPE = "ellipse";
constexpr std::string_view REGULAR_POLYGON_SHAPE_TYPE = "regular-polygon";

constexpr auto FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG = "Failed to create shape. Not enough arguments in description";

ShapeSharedPtr MakeShape(ShapeType type, Color color, std::istream& is)
{
	switch (type)
	{
	case ShapeType::RECTANGLE:
		break;
	case ShapeType::TRIANGLE:
		break;
	case ShapeType::ELLIPSE:
		break;
	case ShapeType::REGULAR_POLYGON:
		break;
	case ShapeType::UNKNOWN:
		break;
	}

	return nullptr;
}

ShapeSharedPtr ShapeFactory::CreateShape(const std::string& description) const
{
	std::stringstream ss{ description };
	ShapeType shapeType;
	Color color{};

	ss >> shapeType;
	if (ss.eof())
	{
		throw std::invalid_argument(FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG);
	}
	if (shapeType == ShapeType::UNKNOWN)
	{
		throw std::invalid_argument("Failed to read shape's type and create shape");
	}

	ss >> color;
	if (color == Color::UNKNOWN)
	{
		throw std::invalid_argument("Failed to read shape's color and create shape");
	}
	if (ss.eof())
	{
		throw std::invalid_argument(FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG);
	}

	ShapeSharedPtr ptr = MakeShape(shapeType, color, ss);

	if (ptr == nullptr)
	{
		throw std::invalid_argument("Failed to create shape. No such shape");
	}

	return ptr;
}
