#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_humidityStatHolder()
	, m_pressureStatHolder()
	, m_temperatureStatHolder()
{
}

void StatsDisplay::Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateSource)
{
	m_humidityStatHolder.TakeNextValue(data.humidity);
	m_pressureStatHolder.TakeNextValue(data.pressure);
	m_temperatureStatHolder.TakeNextValue(data.temperature);

	std::cout << "Humidity:\n"
			  << StatHolderToString(m_humidityStatHolder)
			  << "Pressure:\n"
			  << StatHolderToString(m_pressureStatHolder)
			  << "Temperature:\n"
			  << StatHolderToString(m_temperatureStatHolder) + '\n';
}
