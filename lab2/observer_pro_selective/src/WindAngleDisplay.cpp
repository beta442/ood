#include <iostream>

#include "../include/EventHolder.hpp"
#include "../include/WeatherData.hpp"
#include "../include/WindAngleDisplay.h"

constexpr auto onWindInfoChange{
	[](auto& data) {
		std::cout << "Current Wind angle " << data.windAngle << '\n'
				  << "----------------" << '\n';
	}
};

WindAngleDisplay::WindAngleDisplay()
{
	m_unsubscriber = EventHolder<WindInfo>::AddListener(onWindInfoChange);
}

WindAngleDisplay::~WindAngleDisplay()
{
	m_unsubscriber();
}
