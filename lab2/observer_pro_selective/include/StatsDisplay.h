#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "EventHolder.hpp"
#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay
{
public:
	StatsDisplay();
	~StatsDisplay();

private:
	constexpr auto OnWeatherWindInfoChange()
	{
		return [this](auto& data) {
			m_humidityStatHolder->TakeNextValue(data.weatherInfo.humidity);
			m_pressureStatHolder->TakeNextValue(data.weatherInfo.pressure);
			m_temperatureStatHolder->TakeNextValue(data.weatherInfo.temperature);
			m_windAngleHolder->TakeNextValue(data.windInfo.windAngle);
			m_windSpeedHolder->TakeNextValue(data.windInfo.windSpeed);

			std::cout << "Humidity:\n"
					  << StatHolderToString(*m_humidityStatHolder)
					  << "Pressure:\n"
					  << StatHolderToString(*m_pressureStatHolder)
					  << "Temperature:\n"
					  << StatHolderToString(*m_temperatureStatHolder) + '\n'
					  << "Wind angle:\n"
					  << WindAngleStatHolderToString(*m_windAngleHolder) + '\n'
					  << "Wind speed:\n"
					  << StatHolderToString(*m_windSpeedHolder) + '\n';
		};
	}

	StatisticValueHolder<double>* m_humidityStatHolder;
	StatisticValueHolder<double>* m_pressureStatHolder;
	StatisticValueHolder<double>* m_temperatureStatHolder;

	WindAngleStatisticHolder* m_windAngleHolder;
	StatisticValueHolder<double>* m_windSpeedHolder;
};

#endif // !STATSDISPLAY_H
