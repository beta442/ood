#include <iostream>

#include "../include/EventHolder.hpp"
#include "../include/WeatherData.hpp"
#include "../include/WindSpeedDisplay.h"

constexpr auto onWindInfoChange{
	[](auto& data) {
		std::cout << "Current Wind speed " << data.windSpeed << '\n'
				  << "----------------" << '\n';
	}
};

WindSpeedDisplay::WindSpeedDisplay()
{
	m_unsubscriber = EventHolder<WindInfo>::AddListener(onWindInfoChange);
}

WindSpeedDisplay::~WindSpeedDisplay()
{
	m_unsubscriber();
}
