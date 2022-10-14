#include <sstream>
#include <vector>

#include "../../../include/Shapes/Factory/ShapeFactory.h"

#include "../../../include/Shapes/Ellipse.h"
#include "../../../include/Shapes/Rectangle.h"
#include "../../../include/Shapes/RegularPolygon.h"
#include "../../../include/Shapes/Triangle.h"
#include "../../../include/Shapes/ShapeType.hpp"

ShapeSharedPtr MakeShape(ShapeType type, Color color, std::istream& is)
{
	Point p{};

	is >> p;
	if (is.fail())
	{
		throw std::invalid_argument("Failed to read shape's _2 parameter {Point}.");
	}

	size_t argumentCount = 3;
	switch (type)
	{
	case ShapeType::ELLIPSE: {
		double verticalR{}, horizontalR{};

		is >> verticalR;
		if (is.fail())
		{
			throw std::invalid_argument("Failed to read ellipse's _3 parameter.");
		}

		is >> horizontalR;
		if (is.fail())
		{
			throw std::invalid_argument("Failed to read ellipse's _4 parameter.");
		}

		return std::make_shared<Ellipse>(p, verticalR, horizontalR, color);
	}
	case ShapeType::RECTANGLE: {
		double width{}, height{};

		is >> width;
		if (is.fail())
		{
			throw std::invalid_argument("Failed to read rectangle's _3 parameter.");
		}

		is >> height;
		if (is.fail())
		{
			throw std::invalid_argument("Failed to read rectangle's _4 parameter.");
		}

		return std::make_shared<Rectangle>(p, width, height, color);
	}
	case ShapeType::REGULAR_POLYGON: {
		std::vector<Point> points{ p };
		points.reserve(16);

		while (is.good())
		{
			is >> p;
			if (is.fail())
			{
				throw std::invalid_argument("Failed to read regular-polygon's _" + std::to_string(++argumentCount) + " point");
			}

			points.emplace_back(std::move(p));
		}
		points.shrink_to_fit();

		return std::make_shared<RegularPolygon>(std::move(points), color);
	}
	case ShapeType::TRIANGLE: {
		std::vector<Point> points{ p };
		points.reserve(3);

		while (is.good())
		{
			is >> p;
			if (is.fail())
			{
				throw std::invalid_argument("Failed to read triangle's _" + std::to_string(++argumentCount) + " point");
			}

			points.emplace_back(std::move(p));
		}

		return std::make_shared<Triangle>(std::move(points), color);
	}
	}

	return nullptr;
}

constexpr auto FAILED_TO_CRATE_SHAPE_NOT_ENOUGH_ARGS_MSG = "Failed to create shape. Not enough arguments in description";

ShapeSharedPtr ShapeFactory::CreateShape(const std::string& description) const
{
	std::stringstream ss{ description };
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
