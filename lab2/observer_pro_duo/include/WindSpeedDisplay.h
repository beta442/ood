#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "Observer.h"
#include "../include/WeatherData.hpp"

class WindSpeedDisplay : public IObserver<WeatherWindInfo>
{
private:
	void Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource) override;
};

#endif // !WINDSPEEDDISPLAY_H
