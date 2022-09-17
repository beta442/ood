#include <iostream>

#include "../include/WindAngleDisplay.h"

void WindAngleDisplay::Update(const WeatherInfo& data)
{
	std::cout << "Current Wind angle " << data.windInfo.windAngle << std::endl;
	std::cout << "----------------" << std::endl;
}
