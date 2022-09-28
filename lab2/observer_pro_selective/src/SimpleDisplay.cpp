#include "../include/pch.h"

#include "../include/EventHolder.hpp"
#include "../include/SimpleDisplay.h"
#include "../include/WeatherData.hpp"

constexpr auto onWeatherInfoChange{
	[](auto& data) {
		std::cout << "Current Temp: " << data.temperature << '\n'
				  << "Current Hum: " << data.humidity << '\n'
				  << "Current Pressure: " << data.pressure << '\n'
				  << "----------------" << '\n';
	}
};

SimpleDisplay::SimpleDisplay()
{
	EventHolder<WeatherInfo>::AddListener(onWeatherInfoChange);
}

SimpleDisplay::~SimpleDisplay()
{
	EventHolder<WeatherInfo>::RemoveListener(onWeatherInfoChange);
}
