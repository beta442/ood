#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay(const IObservable<WeatherInfo>& inDoors, const IObservable<WeatherInfo>& outDoors)
	: m_statistics({
		{ StatisticType::INDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() },
		{ StatisticType::UNKNOWN, WeatherStatistic() }
	})
	, m_inDoors(&inDoors)
	, m_outDoors(&outDoors)
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data)
{
	stats.humidityStatHolder->TakeNextValue(data.humidity);
	stats.pressureStatHolder->TakeNextValue(data.pressure);
	stats.temperatureStatHolder->TakeNextValue(data.temperature);

	std::cout << "Humidity\n"
			  << StatHolderToString(*(stats.humidityStatHolder)) + '\n'
			  << "Pressure\n"
			  << StatHolderToString(*(stats.pressureStatHolder)) + '\n'
			  << "Temperature\n"
			  << StatHolderToString(*(stats.temperatureStatHolder)) + '\n';
}

void StatsDisplay::Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateInitiator)
{
	bool inDoors = &updateInitiator == m_inDoors;
	bool outDoors = &updateInitiator == m_outDoors;

	auto& stats = m_statistics[((inDoors)
			? StatisticType::INDOORS
			: (outDoors) ? StatisticType::OUTDOORS
						 : StatisticType::UNKNOWN)];
	StatsUpdate(stats, data);
}
