#include <iostream>

#include "../include/WindAngleDisplay.h"

constexpr auto onWindChange{
	[](auto& _, auto& newWeatherInfo) noexcept {
		std::cout << "Current Wind angle " << newWeatherInfo.GetWindAngle() << '\n'
				  << "----------------" << '\n';
	}
};

WindAngleDisplay::WindAngleDisplay(WeatherInfoStation& stationOut)
{
	stationOut.Connect(onWindChange);
}
