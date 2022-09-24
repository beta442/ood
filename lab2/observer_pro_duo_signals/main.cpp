#include "include/pch.h"

#include "include/WeatherData.hpp"

#include "include/DisplayDuo.h"
#include "include/StatsDisplay.h"
#include "include/WindAngleDisplay.h"
#include "include/WindSpeedDisplay.h"

#include "include/SignallingValue.hpp"

#include <algorithm>

int main()
{
	Observer::SignallingValue<int> m{ 10 };
	m.Connect([](int a, int b) { std::cout << a << " " << b << " hahaha" << '\n'; });
	m.SetValue(20);

	/*WeatherData<false> wdIn;
	WeatherData wdOut;

	WindSpeedDisplay windSpeedDisplay;
	WindAngleDisplay windAngleDisplay;

	wdOut.RegisterObserver(windSpeedDisplay);
	wdOut.RegisterObserver(windAngleDisplay);

	DisplayDuo display;
	wdIn.RegisterObserver(display);
	wdOut.RegisterObserver(display);

	StatsDisplay statsDisplay;
	wdIn.RegisterObserver(statsDisplay);
	wdOut.RegisterObserver(statsDisplay);

	wdIn.SetMeasurements({ 3, 0.7, 760 });
	wdIn.SetMeasurements({ 3, 0.7, 760 });
	wdOut.SetMeasurements({ 40, 355, 3, 0.7, 760 });
	wdOut.SetMeasurements({ 900, 359, 3, 0.7, 760 });*/

	return 0;
}
