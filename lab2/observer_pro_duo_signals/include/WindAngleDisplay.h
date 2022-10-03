#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "SignallingValue.hpp"
#include "WeatherData.hpp"

class WindAngleDisplay
{
public:
	WindAngleDisplay(WeatherData*);
	~WindAngleDisplay();

private:
	Signal::Connection m_stationConnection;
};

#endif // !WINDANGLEDISPLAY_H
