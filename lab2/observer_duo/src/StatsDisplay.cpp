#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_statistics({
		{ StatisticType::INDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() }
	})
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data)
{
	stats.humidityStatHolder->TakeNextValue(data.humidity);
	stats.pressureStatHolder->TakeNextValue(data.pressure);
	stats.temperatureStatHolder->TakeNextValue(data.temperature);

	std::cout << StatHolderToString(*(stats.humidityStatHolder)) + '\n'
			  << StatHolderToString(*(stats.pressureStatHolder)) + '\n'
			  << StatHolderToString(*(stats.temperatureStatHolder)) + '\n';
}

void StatsDisplay::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	bool inDoors = (typeid(WeatherData<false>) == typeid(updateInitiator));

	StatsUpdate(m_statistics[((inDoors) ? StatisticType::INDOORS : StatisticType::OUTDOORS)], data);
}
