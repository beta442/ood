#include "../include/pch.h"

#include "../include/Display.h"

void Display::Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource)
{
	std::cout << "Current Temp: " << data.weatherInfo.temperature << '\n'
			  << "Current Hum: " << data.weatherInfo.humidity << '\n'
			  << "Current Pressure: " << data.weatherInfo.pressure << '\n'
			  << "Current Wind angle: " << data.windInfo.windAngle << '\n'
			  << "Current Wind speed: " << data.windInfo.windSpeed << '\n'
			  << "----------------" << '\n';
}
