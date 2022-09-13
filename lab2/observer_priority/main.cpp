#include "include/pch.h"

#include "include/WeatherData.h"

#include "include/Display.h"
#include "include/StatsDisplay.h"

int main()
{
	WeatherData wd;

	Display display;
	wd.RegisterObserver(0, display);

	StatsDisplay statsDisplay;
	wd.RegisterObserver(10, statsDisplay);

	wd.SetMeasurements(3, 0.7, 760);
	wd.SetMeasurements(4, 0.8, 761);

	wd.RemoveObserver(statsDisplay);

	wd.SetMeasurements(10, 0.8, 761);
	wd.SetMeasurements(-10, 0.8, 761);

	return 0;
}
