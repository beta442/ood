#ifndef DISPLAY_H
#define DISPLAY_H

#include "EventHolder.hpp"

class Display
{
public:
	Display(IEventInitiator* weatherData);
	~Display();

private:
	Unsubscriber m_unsubscriber;
};

#endif // !DISPLAY_H
