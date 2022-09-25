#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include <map>
#include <memory>

#include "Observer.h"
#include "WeatherData.hpp"

class StatsDisplay
{
public:
	using WeatherInfoStation = Observer::IObservable<WeatherWindInfo>;

	StatsDisplay(WeatherInfoStation& stationIn, WeatherInfoStation& stationOut);
};

#endif // !STATSDISPLAY_H
