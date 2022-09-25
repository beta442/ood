#ifndef DISPLAYDUO_H
#define DISPLAYDUO_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class DisplayDuo
{
public:
	using WeatherInfoStation = Observer::IObservable<WeatherWindInfo>;

	DisplayDuo(WeatherInfoStation& stationIn, WeatherInfoStation& stationOut);
};

#endif // !DISPLAYDUO_H
