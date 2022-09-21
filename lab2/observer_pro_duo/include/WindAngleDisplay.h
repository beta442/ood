#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "Observer.h"
#include "WeatherData.h"

class WindAngleDisplay : public IObserver<WeatherWindInfo>
{
private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;
};

#endif // !WINDANGLEDISPLAY_H
