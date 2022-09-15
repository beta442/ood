#include "include/pch.h"

#include "include/WeatherData.h"

#include "include/Display.h"
#include "include/StatsDisplay.h"

int main()
{
	WeatherData inWD, outWD;

	Display display{ &inWD, &outWD };
	inWD.RegisterObserver(display);

	StatsDisplay statsDisplay{ &inWD, &outWD };
	inWD.RegisterObserver(statsDisplay);

	inWD.SetMeasurements(3, 0.7, 760);
	inWD.SetMeasurements(1, 0.1, 730);
	outWD.SetMeasurements(4, 0.8, 761);
	outWD.SetMeasurements(3, 0.7, 760);

	return 0;
}
