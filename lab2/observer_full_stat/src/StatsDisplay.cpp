#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_humidityStatHolder("humidity")
	, m_pressureStatHolder("pressure")
	, m_temperatureStatHolder("temperature")
{
}

void StatsDisplay::Update(const WeatherInfo& data)
{
	m_humidityStatHolder.TakeNextValue(data.humidity);
	m_pressureStatHolder.TakeNextValue(data.pressure);
	m_temperatureStatHolder.TakeNextValue(data.temperature);

	std::cout << m_humidityStatHolder.ToString() + '\n' <<
		m_pressureStatHolder.ToString() + '\n' <<
		m_temperatureStatHolder.ToString() + '\n';
}
