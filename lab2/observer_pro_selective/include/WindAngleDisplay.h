#ifndef WINDANGLEDISPLAY_H
#define WINDANGLEDISPLAY_H

#include "EventHolder.hpp"

class WindAngleDisplay
{
public:
	WindAngleDisplay(IEventInitiator* weatherData);
	~WindAngleDisplay();

private:
	Unsubscriber m_unsubscriber;
};

#endif // !WINDANGLEDISPLAY_H
