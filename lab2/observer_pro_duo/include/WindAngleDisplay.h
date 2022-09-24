#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "Observer.h"
#include "WeatherData.hpp"

class WindAngleDisplay : public IObserver<WeatherWindInfo>
{
private:
	void Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource) override;
};

#endif // !WINDANGLEDISPLAY_H
