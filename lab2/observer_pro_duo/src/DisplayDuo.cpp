#include "../include/pch.h"

#include "../include/DisplayDuo.h"

void DisplayDuo::Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource)
{
	bool inDoors = typeid(WeatherData<false>) == typeid(updateSource);
	bool outDoors = typeid(WeatherData<true>) == typeid(updateSource);

	std::cout << (inDoors
			? "INDOORS:\n"
			: outDoors ? "OUTDOORS:\n"
					   : "UNKOWN TYPE SOURCE:\n");

	std::cout << "Current Temp: " << data.weatherInfo.temperature << '\n'
			  << "Current Hum: " << data.weatherInfo.humidity << '\n'
			  << "Current Pressure: " << data.weatherInfo.pressure << '\n';

	if (outDoors)
	{
		std::cout << "Current Wind angle: " << data.windInfo.windAngle << '\n'
				  << "Current Wind speed: " << data.windInfo.windSpeed << '\n';
	}
	std::cout << "----------------" << '\n';
}
