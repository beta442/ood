#include <iostream>

#include "../include/WindAngleDisplay.h"

void WindAngleDisplay::Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource)
{
	std::cout << "Current Wind angle " << data.windInfo.windAngle << std::endl;
	std::cout << "----------------" << std::endl;
}
