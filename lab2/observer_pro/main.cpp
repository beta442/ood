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
	wd.RegisterObserver(display);

	StatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay);

	WindSpeedDisplay windSpeedDisplay;
	wd.RegisterObserver(windSpeedDisplay);

	WindAngleDisplay windAngleDisplay;
	wd.RegisterObserver(windAngleDisplay);

	wd.SetMeasurements({ 40, 370, 3, 0.7, 760 });
	wd.SetMeasurements({ 10, 20, 4, 0.15, 761 });

	return 0;
}
