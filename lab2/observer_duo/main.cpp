#include "include/pch.h"

#include "include/WeatherData.hpp"

#include "include/Display.h"
#include "include/StatsDisplay.h"

int main()
{
	WeatherData<false> inWD;
	WeatherData outWD;

	Display display{ inWD, outWD };
	inWD.RegisterObserver(display);
	outWD.RegisterObserver(display);

	StatsDisplay statsDisplay{ inWD, outWD };
	inWD.RegisterObserver(statsDisplay);
	outWD.RegisterObserver(statsDisplay);

	inWD.SetMeasurements(3, 0.7, 760);
	inWD.SetMeasurements(1, 0.1, 730);
	outWD.SetMeasurements(4, 0.8, 761);
	outWD.SetMeasurements(3, 0.7, 760);

	return 0;
}
