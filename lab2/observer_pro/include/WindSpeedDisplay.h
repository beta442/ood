#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "Observer.h"
#include "../include/WeatherData.h"

class WindSpeedDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource) override;
};

#endif // !WINDSPEEDDISPLAY_H
