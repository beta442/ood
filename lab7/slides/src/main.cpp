#include "pch.h"

#include "slide/CSlide/Slide.h"

#include "drawer/DrawerSFML.h"

#include "slide/former/Examples.h"

int main()
{
	using namespace slide;
	using namespace drawer;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	auto renderWindow = std::make_shared<sf::RenderWindow>(
		sf::VideoMode(1024, 720, 16),
		"Slide",
		sf::Style::Titlebar | sf::Style::Close,
		settings);

	auto slide = std::make_shared<Slide>();
	auto sfmlDrawer = DrawerSFML(renderWindow, slide);

	demo::FormSlideWithComputerScreenPicture(*slide);

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
		}

		renderWindow->display();
	}

	return 0;
}
