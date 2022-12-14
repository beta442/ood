#ifndef DISPLAY_H
#define DISPLAY_H

#include "../include/Observer.h"
#include "../include/WeatherData.h"

class Display : public IObserver<WeatherInfo>
{
	void Update(const WeatherInfo& data) override;
};

#endif // !DISPLAY_H
