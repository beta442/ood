#include "include/pch.h"

#include "include/WeatherData.hpp"

#include "include/DisplayDuo.h"
#include "include/StatsDisplay.h"
#include "include/WindAngleDisplay.h"
#include "include/WindSpeedDisplay.h"

#include "include/SignallingValue.hpp"

int main()
{
	WeatherData<false> wdIn;
	WeatherData wdOut;

	DisplayDuo display{ wdIn, wdOut };
	StatsDisplay statsDisplay{ wdIn, wdOut };

	WindSpeedDisplay windSpeedDisplay{ wdOut };
	WindAngleDisplay windAngleDisplay{ wdOut };

	wdIn.SetMeasurements({ 3, 0.7, 760 });
	wdIn.SetMeasurements({ 3, 0.7, 760 });
	wdOut.SetMeasurements({ 40, 355, 3, 0.7, 760 });
	wdOut.SetMeasurements({ 900, 359, 3, 0.7, 760 });

	return 0;
}
