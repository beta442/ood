#ifndef SHAPES_SHAPE_TYPE_HPP_
#define SHAPES_SHAPE_TYPE_HPP_

#include <sstream>
#include <string>

#include "../utility/IEqualString.hpp"

enum class ShapeType
{
	RECTANGLE = 0,
	TRIANGLE,
	ELLIPSE,
	REGULAR_POLYGON,
	UNKNOWN,
};

namespace shapes_string_types
{

constexpr std::string_view RECTANGLE_TYPE = "rectangle";
constexpr std::string_view TRIANGLE_TYPE = "triangle";
constexpr std::string_view ELLIPSE_TYPE = "ellipse";
constexpr std::string_view REGULAR_POLYGON_TYPE = "regular-polygon";

}; // namespace shapes_string_types

template <typename StringT>
ShapeType StringToShapeType(StringT&& str)
{
	using namespace shapes_string_types;

	if (IEqualStrings(std::forward<StringT>(str), RECTANGLE_TYPE))
	{
		return ShapeType::RECTANGLE;
	}
	if (IEqualStrings(std::forward<StringT>(str), TRIANGLE_TYPE))
	{
		return ShapeType::TRIANGLE;
	}
	if (IEqualStrings(std::forward<StringT>(str), ELLIPSE_TYPE))
	{
		return ShapeType::ELLIPSE;
	}
	if (IEqualStrings(std::forward<StringT>(str), REGULAR_POLYGON_TYPE))
	{
		return ShapeType::REGULAR_POLYGON;
	}
	return ShapeType::UNKNOWN;
}

std::istream& operator>>(std::istream& lhs, ShapeType rhs)
{
	if (!std::istream::sentry(lhs))
	{
		rhs = ShapeType::UNKNOWN;
		return lhs;
	}

	std::string src;
	lhs >> src;

	rhs = StringToShapeType(std::move(src));

	return lhs;
}

#endif // !SHAPES_SHAPE_TYPE_HPP_
