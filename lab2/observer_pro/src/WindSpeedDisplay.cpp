#include <iostream>

#include "../include/WindSpeedDisplay.h"

void WindSpeedDisplay::Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource)
{
	std::cout << "Current Wind speed " << data.windInfo.windSpeed << std::endl;
	std::cout << "----------------" << std::endl;
}
