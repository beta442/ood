#include <iostream>

#include "../include/WindSpeedDisplay.h"

constexpr auto onWindSpeedChange{
	[](auto& _, auto& newWeatherInfo) noexcept {
		std::cout << "Current Wind speed " << newWeatherInfo.GetWindSpeed() << '\n'
				  << "----------------" << '\n';
	}
};

WindSpeedDisplay::WindSpeedDisplay(WeatherInfoStation& stationOut)
{
	stationOut.Connect(onWindSpeedChange);
}
