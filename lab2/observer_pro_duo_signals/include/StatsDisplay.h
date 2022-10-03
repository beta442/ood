#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "SignallingValue.hpp"
#include "WeatherData.hpp"

class StatsDisplay
{
public:
	StatsDisplay(WeatherData*, WeatherData*);
	~StatsDisplay();

private:
	Signal::Connection m_connectionStationIn, m_connectionStationOut;
};

#endif // !STATSDISPLAY_H
