#ifndef DISPLAYDUO_H
#define DISPLAYDUO_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class DisplayDuo : public IObserver<WeatherWindInfo>
{
private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;
};

#endif // !DISPLAYDUO_H
