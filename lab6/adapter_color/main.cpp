#include "include/pch.h"

#include "app/PaintPictureOnCanvas.h"

int main(int, char**)
{
	std::cout << "Should we use new API (y)?\n";
	if (std::string userInput;
		std::getline(std::cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return 0;
}
