#ifndef WINDSPEEDDISPLAY_H
#define WINDSPEEDDISPLAY_H

#include "EventHolder.hpp"

class WindSpeedDisplay
{
public:
	WindSpeedDisplay();
	~WindSpeedDisplay();

private:
	Unsubscriber m_unsubscriber;
};

#endif // !WINDSPEEDDISPLAY_H
