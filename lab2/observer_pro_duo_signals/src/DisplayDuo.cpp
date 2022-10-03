#include "../include/pch.h"

#include "../include/DisplayDuo.h"

constexpr auto onWeatherChange{
	[](auto& _, auto& currWeatherInfo) noexcept {
		std::cout << "INDOORS\n";

		std::cout << "Current Temp: " << currWeatherInfo.temperature << '\n'
				  << "Current Hum: " << currWeatherInfo.humidity << '\n'
				  << "Current Pressure: " << currWeatherInfo.pressure << '\n'
				  << "---------------------------------------------\n"; 
	}
};

constexpr auto onWeatherWindChange{
	[](auto& _, auto& currWeatherWindInfo) noexcept {
		std::cout << "OUTDOORS\n";

		std::cout << "Current Temp: " << currWeatherWindInfo.weatherInfo.temperature << '\n'
				  << "Current Hum: " << currWeatherWindInfo.weatherInfo.humidity << '\n'
				  << "Current Pressure: " << currWeatherWindInfo.weatherInfo.pressure << '\n';

		std::cout << "Current Wind angle: " << currWeatherWindInfo.windInfo.angle << '\n'
				  << "Current Wind speed: " << currWeatherWindInfo.windInfo.speed << '\n'
				  << "---------------------------------------------\n";
	}
};

DisplayDuo::DisplayDuo(WeatherData* stationIn, WeatherData* stationOut)
{
	m_connectionStationIn = stationIn->OnWeatherChange(onWeatherChange);
	m_connectionStationOut = stationOut->OnWeatherWindChange(onWeatherWindChange);
}

DisplayDuo::~DisplayDuo()
{
	m_connectionStationIn.disconnect();
	m_connectionStationOut.disconnect();
}
