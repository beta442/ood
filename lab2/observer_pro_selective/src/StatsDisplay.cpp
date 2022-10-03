#include "../include/pch.h"

#include "../include/EventHolder.hpp"
#include "../include/StatsDisplay.h"
#include "../include/WeatherData.hpp"

StatsDisplay::StatsDisplay(IEventInitiator* weatherData)
	: m_humidityStatHolder(new StatisticValueHolder())
	, m_pressureStatHolder(new StatisticValueHolder())
	, m_temperatureStatHolder(new StatisticValueHolder())
	, m_windAngleHolder(new WindAngleStatisticHolder())
	, m_windSpeedHolder(new StatisticValueHolder())
{
	m_unsubscriber = EventHolder<WeatherWindInfo>::AddListener(weatherData, [this](auto& data) {
		UpdateStatistics(data);
	});
}

StatsDisplay::~StatsDisplay()
{
	delete m_humidityStatHolder;
	delete m_pressureStatHolder;
	delete m_temperatureStatHolder;
	delete m_windAngleHolder;
	delete m_windSpeedHolder;

	m_unsubscriber();
}

void StatsDisplay::UpdateStatistics(const WeatherWindInfo& info)
{
	m_humidityStatHolder->TakeNextValue(info.weatherInfo.humidity);
	m_pressureStatHolder->TakeNextValue(info.weatherInfo.pressure);
	m_temperatureStatHolder->TakeNextValue(info.weatherInfo.temperature);
	m_windAngleHolder->TakeNextValue(info.windInfo.windAngle);
	m_windSpeedHolder->TakeNextValue(info.windInfo.windSpeed);

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
}
