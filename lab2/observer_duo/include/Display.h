#ifndef DISPLAY_H
#define DISPLAY_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class Display : public AbstractObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo& data, Observable& updateInitiator) override;
};

#endif // !DISPLAY_H
