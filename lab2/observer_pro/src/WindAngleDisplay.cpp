#include <iostream>

#include "../include/WindAngleDisplay.h"

void WindAngleDisplay::Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource)
{
	std::cout << "Current Wind angle " << data.windInfo.windAngle << std::endl;
	std::cout << "----------------" << std::endl;
}
