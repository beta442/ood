#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_humidityStatHolder(new StatisticValueHolder())
	, m_pressureStatHolder(new StatisticValueHolder())
	, m_temperatureStatHolder(new StatisticValueHolder())
	, m_windAngleHolder(new WindAngleStatisticHolder())
	, m_windSpeedHolder(new StatisticValueHolder<double>())
{
}

StatsDisplay::~StatsDisplay()
{
	delete m_humidityStatHolder;
	delete m_pressureStatHolder;
	delete m_temperatureStatHolder;
	delete m_windAngleHolder;
	delete m_windSpeedHolder;
}

void StatsDisplay::Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource)
{
	m_humidityStatHolder->TakeNextValue(data.humidity);
	m_pressureStatHolder->TakeNextValue(data.pressure);
	m_temperatureStatHolder->TakeNextValue(data.temperature);
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
}
