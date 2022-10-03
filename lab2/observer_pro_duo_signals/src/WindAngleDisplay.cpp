#include <iostream>

#include "../include/WindAngleDisplay.h"

constexpr auto onWindAngleChange{
	[](auto& _, auto& windAngle) noexcept {
		std::cout << "Current Wind angle: " << windAngle << '\n'
				  << "---------------------------------------------\n";
	}
};

WindAngleDisplay::WindAngleDisplay(WeatherData* station)
{
	m_stationConnection = station->OnWindAngleChange(onWindAngleChange);
}

WindAngleDisplay::~WindAngleDisplay()
{
	m_stationConnection.disconnect();
}
