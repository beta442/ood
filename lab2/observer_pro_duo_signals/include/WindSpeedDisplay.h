#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "SignallingValue.hpp"
#include "../include/WeatherData.hpp"

class WindSpeedDisplay
{
public:
	WindSpeedDisplay(WeatherData*);
	~WindSpeedDisplay();

private:
	Signal::Connection m_stationConnection;
};

#endif // !WINDSPEEDDISPLAY_H
