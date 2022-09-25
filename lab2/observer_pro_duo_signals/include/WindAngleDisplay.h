#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "Observer.h"
#include "WeatherData.hpp"

class WindAngleDisplay
{
public:
	using WeatherInfoStation = Observer::IObservable<WeatherWindInfo>;

	WindAngleDisplay(WeatherInfoStation& stationOut);
};

#endif // !WINDANGLEDISPLAY_H
