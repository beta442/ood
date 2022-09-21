#include "../include/pch.h"

#include "../include/DisplayDuo.h"

DisplayDuo::DisplayDuo(Observable<WeatherWindInfo>& indoorsStation, Observable<WeatherWindInfo>& outdoorsStation)
	: m_indoorsStation(&indoorsStation)
	, m_outdoorsStation(&outdoorsStation)
{
}

void DisplayDuo::Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource)
{
	bool inDoors = m_indoorsStation == &updateSource;
	bool outDoors = m_outdoorsStation == &updateSource;
	
	std::cout << (inDoors
			? "INDOORS:\n"
			: outDoors
			? "OUTDOORS:\n"
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
