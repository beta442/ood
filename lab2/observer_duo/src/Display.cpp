#include <algorithm>

#include "../include/pch.h"

#include "../include/Display.h"

Display::Display(const IObservable<WeatherInfo>& inDoors, const IObservable<WeatherInfo>& outDoors)
	: m_inDoors(&inDoors)
	, m_outDoors(&outDoors)
{
}

void Display::Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateInitiator)
{
	bool inDoors = &updateInitiator == m_inDoors;
	bool outDoors = &updateInitiator == m_outDoors;

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
