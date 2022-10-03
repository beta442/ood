#include <iostream>

#include "../include/WindSpeedDisplay.h"

constexpr auto onWindSpeedChange{
	[](auto& _, auto& windSpeed) noexcept {
		std::cout << "Current Wind speed: " << windSpeed << '\n'
				  << "---------------------------------------------\n";
	}
};

WindSpeedDisplay::WindSpeedDisplay(WeatherData* station)
{
	m_stationConnection = station->OnWindSpeedChange(onWindSpeedChange);
}

WindSpeedDisplay::~WindSpeedDisplay()
{
	m_stationConnection.disconnect();
}
