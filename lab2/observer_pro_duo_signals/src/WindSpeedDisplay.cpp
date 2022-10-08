#include <iostream>

#include "../include/WindSpeedDisplay.h"

constexpr auto onWeatherWindChange{
	[](auto& _, auto& data) noexcept {
		std::cout << "Current Wind speed: " << data.windInfo.speed << '\n'
				  << "---------------------------------------------\n";
	}
};

WindSpeedDisplay::WindSpeedDisplay(WeatherData* station)
{
	m_stationConnection = station->OnWeatherWindChange(onWeatherWindChange);
}

WindSpeedDisplay::~WindSpeedDisplay()
{
	m_stationConnection.disconnect();
}
