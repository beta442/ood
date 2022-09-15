#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay(Observable* indoorsWD, Observable* outdoorsWD)
	: m_updaterToStatisticMap({
		{ indoorsWD, { StatisticValueHolder("humidity"), StatisticValueHolder("pressure"), StatisticValueHolder("temperature") } },
		{ outdoorsWD, { StatisticValueHolder("humidity"), StatisticValueHolder("pressure"), StatisticValueHolder("temperature") } }
	})
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data)
{
	stats.m_humidityStatHolder.TakeNextValue(data.humidity);
	stats.m_pressureStatHolder.TakeNextValue(data.pressure);
	stats.m_temperatureStatHolder.TakeNextValue(data.temperature);

	std::cout << stats.m_humidityStatHolder.ToString() + '\n'
			  << stats.m_pressureStatHolder.ToString() + '\n'
			  << stats.m_temperatureStatHolder.ToString() + '\n';
}

void StatsDisplay::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	if (m_updaterToStatisticMap.find(&updateInitiator) != std::end(m_updaterToStatisticMap))
	{
		StatsUpdate(m_updaterToStatisticMap[&updateInitiator], data);
	}
}
