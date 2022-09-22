#ifndef DISPLAY_H
#define DISPLAY_H

#include "../include/Observer.h"
#include "../include/WeatherData.h"

class Display : public IObserver<WeatherWindInfo>
{
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;
};

#endif // !DISPLAY_H
