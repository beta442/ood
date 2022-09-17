#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "Observer.h"
#include "WeatherData.h"

class WindAngleDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo& data) override;
};

#endif // !WINDANGLEDISPLAY_H
