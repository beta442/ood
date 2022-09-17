#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_humidityStatHolder("humidity")
	, m_pressureStatHolder("pressure")
	, m_temperatureStatHolder("temperature")
	, m_windAngleHolder("wind angle")
	, m_windSpeedHolder("wind speed")
{
}

void StatsDisplay::Update(const WeatherInfo& data)
{
	m_humidityStatHolder.TakeNextValue(data.humidity);
	m_pressureStatHolder.TakeNextValue(data.pressure);
	m_temperatureStatHolder.TakeNextValue(data.temperature);
	m_windAngleHolder.TakeNextValue(data.windInfo.windAngle);
	m_windSpeedHolder.TakeNextValue(data.windInfo.windSpeed);

	std::cout << m_humidityStatHolder.ToString() + '\n'
			  << m_pressureStatHolder.ToString() + '\n'
			  << m_temperatureStatHolder.ToString() + '\n'
			  << m_windAngleHolder.ToString() + '\n'
			  << m_windSpeedHolder.ToString() + '\n';
}
