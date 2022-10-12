#include "include/pch.h"

#include "include/Shapes/RegularPolygon.h"

int main(int, char**)
{
	try
	{
		RegularPolygon p{ std::initializer_list<Point>{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } }, Color::BLACK };

		auto c = p.GetCenter();
		auto r = p.GetRadius();
		std::cout << "Center: " << c.x << " " << c.y << '\n'
				  << "Radius: " << r << '\n';
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
