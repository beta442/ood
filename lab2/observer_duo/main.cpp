#include "include/pch.h"

#include "include/WeatherData.h"

#include "include/Display.h"
#include "include/StatsDisplay.h"

int main()
{
	WeatherData wdIn{ SensorType::INDOORS };
	WeatherData wdOut{ SensorType::OUTDOORS };

	Display display;
	wdIn.RegisterObserver(display);
	wdOut.RegisterObserver(display);

	StatsDisplay statsDisplay;
	wdIn.RegisterObserver(statsDisplay);
	wdOut.RegisterObserver(statsDisplay);

	wdIn.SetMeasurements(1, 0.7, 760);
	wdIn.SetMeasurements(2, 0.8, 761);
	wdIn.SetMeasurements(3, 0.8, 761);
	wdIn.SetMeasurements(-4, 0.8, 761);

	wdOut.SetMeasurements(-1, 0.7, 760);
	wdOut.SetMeasurements(-2, 0.8, 761);
	wdOut.SetMeasurements(-3, 0.8, 761);
	wdOut.SetMeasurements(4, 0.8, 761);

	return 0;
}
