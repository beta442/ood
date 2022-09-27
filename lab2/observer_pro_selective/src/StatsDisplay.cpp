#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_humidityStatHolder(new StatisticValueHolder())
	, m_pressureStatHolder(new StatisticValueHolder())
	, m_temperatureStatHolder(new StatisticValueHolder())
	, m_windAngleHolder(new WindAngleStatisticHolder())
	, m_windSpeedHolder(new StatisticValueHolder())
{
	EventHolder<WeatherWindInfo>::AddListener(OnWeatherWindInfoChange());
}

StatsDisplay::~StatsDisplay()
{
	delete m_humidityStatHolder;
	delete m_pressureStatHolder;
	delete m_temperatureStatHolder;
	delete m_windAngleHolder;
	delete m_windSpeedHolder;
}
