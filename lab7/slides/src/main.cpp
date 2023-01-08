#include "pch.h"

#include "drawable/slide/CSlide/Slide.h"

#include "drawer/DrawerSFML.h"

#include "drawable/former/Examples.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	auto renderWindow = std::make_shared<sf::RenderWindow>(
		sf::VideoMode(1024, 720, 16),
		"Slide",
		sf::Style::Titlebar | sf::Style::Close,
		settings);

	auto slide = std::make_shared<drawable::slide::Slide>();
	auto sfmlDrawer = drawer::DrawerSFML(renderWindow, slide);

	using drawable::slide::demo::FormSlideWithComputerScreenPicture;
	using drawable::slide::demo::SetFillColorToShapesInSlide;
	using drawable::slide::demo::SetSizeToShapesInSlide;

	FormSlideWithComputerScreenPicture(*slide);

	unsigned step = 0;
	while (renderWindow->isOpen())
	{
		renderWindow->clear(sf::Color(255, 255, 255));

		sfmlDrawer.Draw();

		sf::Event event;
		while (renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				renderWindow->close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if (step % 3 == 0)
				{
					SetSizeToShapesInSlide(*slide);
				}
				if (step % 3 == 1)
				{
					SetFillColorToShapesInSlide(*slide);
				}
				if (step % 3 == 2)
				{
					FormSlideWithComputerScreenPicture(*slide);
				}
				if (++step == 3)
				{
					step = 0;
				}
			}
		}

		renderWindow->display();
	}

	return 0;
}
