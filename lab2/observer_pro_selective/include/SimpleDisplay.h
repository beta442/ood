#ifndef SIMPLEDISPLAY_H
#define SIMPLEDISPLAY_H

#include "EventHolder.hpp"

class SimpleDisplay
{
public:
	SimpleDisplay(IEventInitiator* weatherData);
	~SimpleDisplay();

private:
	Unsubscriber m_unsubscriber;
};

#endif // !SIMPLEDISPLAY_H
