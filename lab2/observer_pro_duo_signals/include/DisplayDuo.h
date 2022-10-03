#ifndef DISPLAYDUO_H
#define DISPLAYDUO_H

#include "../include/SignallingValue.hpp"
#include "../include/WeatherData.hpp"

class DisplayDuo
{
public:
	DisplayDuo(WeatherData*, WeatherData*);
	~DisplayDuo();

private:
	Signal::Connection m_connectionStationIn, m_connectionStationOut;
};

#endif // !DISPLAYDUO_H
