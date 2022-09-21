#include "../include/pch.h"

#include "../include/Display.h"

void Display::Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource)
{
	std::cout << "Current Temp " << data.temperature << std::endl;
	std::cout << "Current Hum " << data.humidity << std::endl;
	std::cout << "Current Pressure " << data.pressure << std::endl;
	std::cout << "Current Wind angle" << data.windInfo.windAngle << std::endl;
	std::cout << "Current Wind speed" << data.windInfo.windSpeed << std::endl;
	std::cout << "----------------" << std::endl;
}

