#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay(Observable* indoorsWD, Observable* outdoorsWD)
	: m_updaterToStatisticMap({
		{ indoorsWD, { StatisticValueHolder(), StatisticValueHolder(), StatisticValueHolder() } },
		{ outdoorsWD, { StatisticValueHolder(), StatisticValueHolder(), StatisticValueHolder() } }
	})
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data)
{
	stats.m_humidityStatHolder.TakeNextValue(data.humidity);
	stats.m_pressureStatHolder.TakeNextValue(data.pressure);
	stats.m_temperatureStatHolder.TakeNextValue(data.temperature);

	std::cout << StatHolderToString(stats.m_humidityStatHolder) + '\n'
			  << StatHolderToString(stats.m_pressureStatHolder) + '\n'
			  << StatHolderToString(stats.m_temperatureStatHolder) + '\n';
}

void StatsDisplay::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	if (m_updaterToStatisticMap.find(&updateInitiator) != std::end(m_updaterToStatisticMap))
	{
		StatsUpdate(m_updaterToStatisticMap[&updateInitiator], data);
	}
}
