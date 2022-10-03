#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "EventHolder.hpp"

class WindSpeedDisplay
{
public:
	WindSpeedDisplay(IEventInitiator* weatherData);
	~WindSpeedDisplay();

private:
	Unsubscriber m_unsubscriber;
};

#endif // !WINDSPEEDDISPLAY_H
