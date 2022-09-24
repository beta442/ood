#include <iostream>

#include "../include/WindSpeedDisplay.h"

void WindSpeedDisplay::Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource)
{
	std::cout << "Current Wind speed " << data.windInfo.windSpeed << std::endl;
	std::cout << "----------------" << std::endl;
}
