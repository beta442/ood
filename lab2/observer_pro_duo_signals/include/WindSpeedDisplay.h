#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "Observer.h"
#include "../include/WeatherData.hpp"

class WindSpeedDisplay
{
public:
	using WeatherInfoStation = Observer::IObservable<WeatherWindInfo>;

	WindSpeedDisplay(WeatherInfoStation& stationOut);
};

#endif // !WINDSPEEDDISPLAY_H
