#include "../include/pch.h"

#include "../include/Display.h"
#include "../include/EventHolder.hpp"
#include "../include/WeatherData.hpp"

constexpr auto onWeatherWindInfoChange{
	[](auto& data) {
		std::cout << "Current Temp: " << data.weatherInfo.temperature << '\n'
				  << "Current Hum: " << data.weatherInfo.humidity << '\n'
				  << "Current Pressure: " << data.weatherInfo.pressure << '\n'
				  << "Current Wind angle: " << data.windInfo.windAngle << '\n'
				  << "Current Wind speed: " << data.windInfo.windSpeed << '\n'
				  << "----------------" << '\n';
	}
};

Display::Display(IEventInitiator* weatherData)
{
	m_unsubscriber = EventHolder<WeatherWindInfo>::AddListener(weatherData, onWeatherWindInfoChange);
}

Display::~Display()
{
	m_unsubscriber();
}
