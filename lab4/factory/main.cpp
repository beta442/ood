#include "include/pch.h"

#include "include/Designer/Designer.h"
#include "include/Painter/Painter.h"

int main(int, char**)
{
	try
	{
		Designer designer{};
		auto draft = designer.CreateDraft(std::cin);

		Painter painter{};
		painter.DrawPicture(draft, );
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
