#include "include/pch.h"

#include "include/Shapes/Factory/ShapeFactory.h"

#include "include/Designer/Designer.h"
#include "include/Painter/Painter.h"

int main(int, char**)
{
	try
	{
		ShapeFactory f{};
		auto ellipse = f.CreateShape("ellipse green 26 70 20 40");
		std::cout << ellipse->GetBasePoint().x << " " << ellipse->GetBasePoint().y << " color: " << int(ellipse->GetColor()) << '\n';

		auto rectangle = f.CreateShape("rectangle black 45.99 0.99 100 12");
		std::cout << rectangle->GetBasePoint().x << " " << rectangle->GetBasePoint().y << " color: " << int(rectangle->GetColor()) << '\n';

		auto regularPolygon = f.CreateShape("regular-polygon pink 0 0 0 10 10 10 10 0");
		std::cout << regularPolygon->GetBasePoint().x << " " << regularPolygon->GetBasePoint().y << " color: " << int(regularPolygon->GetColor()) << '\n';

		auto triangle = f.CreateShape("triangle black 10 0 10 10 0 5");
		std::cout << triangle->GetBasePoint().x << " " << triangle->GetBasePoint().y << " color: " << int(triangle->GetColor()) << '\n';
		/*Designer designer{};
		auto draft = designer.CreateDraft(std::cin);

		Painter painter{};*/
		//painter.DrawPicture(draft, );
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
