#include "include/pch.h"

#include "include/WeatherData.h"

#include "include/Display.h"
#include "include/StatsDisplay.h"
#include "include/WindAngleDisplay.h"
#include "include/WindSpeedDisplay.h"

int main()
{
	WeatherData wd;

	Display display;
	wd.RegisterObserver(display, "OnWeatherUpdate");

	StatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, "OnUpdate");

	WindSpeedDisplay windSpeedDisplay;
	wd.RegisterObserver(windSpeedDisplay, "OnWindSpeedUpdate");

	WindAngleDisplay windAngleDisplay;
	wd.RegisterObserver(windAngleDisplay, "OnWindAngleUpdate");

	wd.SetMeasurements({ 40, 370, 3, 0.7, 760 });
	wd.SetMeasurements({ 10, 370, 3, 0.7, 760 });

	return 0;
}
