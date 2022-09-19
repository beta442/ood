#include <algorithm>

#include "../include/pch.h"

#include "../include/Display.h"

void Display::Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateSource)
{
	updateSource.RemoveObserver(*this);

	std::cout << "Current Temp " << data.temperature << std::endl;
	std::cout << "Current Hum " << data.humidity << std::endl;
	std::cout << "Current Pressure " << data.pressure << std::endl;
	std::cout << "----------------" << std::endl;
}

