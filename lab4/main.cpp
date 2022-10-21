#include "include/pch.h"

#include "include/Canvas/SVGCanvas.h"
#include "include/Designer/Designer.h"
#include "include/Painter/Painter.h"

int main(int, char**)
{
	try
	{
		Designer designer{ std::move(std::make_shared<ShapeFactory>()) };
		auto draft = designer.CreateDraft(std::cin);

		Painter painter{};
		ICanvasSharedPtr canvas = std::make_shared<SVGCanvas>("output.svg", 1600, 920);
		painter.DrawPicture(draft, canvas);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
