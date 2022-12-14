#ifndef SHAPES_COMMON_COLOR_HPP_
#define SHAPES_COMMON_COLOR_HPP_

#include <sstream>
#include <string>

#include "../utility/IEqualString.hpp"

enum class Color
{
	BLACK = 0,
	BLUE,
	GREEN,
	PINK,
	RED,
	YELLOW,
	UNKNOWN,
};

namespace color_string_types
{

constexpr std::string_view GREEN_TYPE = "green";
constexpr std::string_view RED_TYPE = "red";
constexpr std::string_view BLUE_TYPE = "blue";
constexpr std::string_view YELLOW_TYPE = "yellow";
constexpr std::string_view PINK_TYPE = "pink";
constexpr std::string_view BLACK_TYPE = "black";

}; // namespace color_string_types

template <typename StringT>
inline Color StringToColor(StringT&& str)
{
	using namespace color_string_types;

	if (IEqualStrings(str, BLACK_TYPE))
	{
		return Color::BLACK;
	}
	else if (IEqualStrings(str, BLUE_TYPE))
	{
		return Color::BLUE;
	}
	else if (IEqualStrings(str, GREEN_TYPE))
	{
		return Color::GREEN;
	}
	else if (IEqualStrings(str, PINK_TYPE))
	{
		return Color::PINK;
	}
	else if (IEqualStrings(str, RED_TYPE))
	{
		return Color::RED;
	}
	else if (IEqualStrings(str, YELLOW_TYPE))
	{
		return Color::YELLOW;
	}
	return Color::UNKNOWN;
}

inline std::istream& operator>>(std::istream& lhs, Color& rhs)
{
	if (!std::istream::sentry(lhs))
	{
		return lhs;
	}

	std::string src;
	lhs >> src;

	auto res = StringToColor(std::move(src));
	if (res == Color::UNKNOWN)
	{
		lhs.setstate(std::ios_base::failbit);
		return lhs;
	}
	rhs = res;

	return lhs;
}

#endif // !SHAPES_COMMON_COLOR_HPP_
