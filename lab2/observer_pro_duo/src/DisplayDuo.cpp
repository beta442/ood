#include "../include/pch.h"

#include "../include/DisplayDuo.h"

DisplayDuo::DisplayDuo(const IObservable<WeatherWindInfo>& inDoors, const IObservable<WeatherWindInfo>& outDoors)
	: m_inDoors(&inDoors)
	, m_outDoors(&outDoors)
{
}

void DisplayDuo::Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource)
{
	bool inDoors = &updateSource == m_inDoors;
	bool outDoors = &updateSource == m_outDoors;

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
