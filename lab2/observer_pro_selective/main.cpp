#include "include/pch.h"

#include "include/WeatherData.hpp"

#include "include/Display.h"
#include "include/StatsDisplay.h"
#include "include/WindAngleDisplay.h"
#include "include/WindSpeedDisplay.h"
#include "include/SimpleDisplay.h"

int main()
{
	WeatherData wd;

	Display display;
	SimpleDisplay simpleDisplay;
	StatsDisplay statsDisplay;
	WindAngleDisplay windAngleDisplay;
	WindSpeedDisplay windSpeedDisplay;

	wd.SetMeasurements(std::move(WeatherWindInfo{ 40, 370, 3, 0.7, 760 }));
	wd.SetMeasurements(std::move(WindInfo{ 40, 370 }));
	wd.SetMeasurements(std::move(WeatherInfo{ 40, 370, 50 }));

	return 0;
}
