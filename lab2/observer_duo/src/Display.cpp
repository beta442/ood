#include <algorithm>

#include "../include/pch.h"

#include "../include/Display.h"

void Display::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	bool inDoors = typeid(WeatherData<false>) == typeid(updateInitiator);
	bool outDoors = typeid(WeatherData<true>) == typeid(updateInitiator);

	std::cout << (inDoors
			? "INDOORS"
			: outDoors ? "OUTDOORS"
					   : "UNKNOWN SOURCE")
			  << ":\n";

	std::cout << "Current Temp " << data.temperature << '\n'
			  << "Current Hum " << data.humidity << '\n'
			  << "Current Pressure " << data.pressure << '\n'
			  << "----------------" << '\n';
}
