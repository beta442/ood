#include <iostream>

#include "../include/WindAngleDisplay.h"

constexpr auto onWeatherWindChange{
	[](auto& _, auto& data) noexcept {
		std::cout << "Current Wind angle: " << data.windInfo.angle << '\n'
				  << "---------------------------------------------\n";
	}
};

WindAngleDisplay::WindAngleDisplay(WeatherData* station)
{
	m_stationConnection = station->OnWeatherWindChange(onWeatherWindChange);
}

WindAngleDisplay::~WindAngleDisplay()
{
	m_stationConnection.disconnect();
}
