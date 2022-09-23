#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_statistics({
		{ StatisticType::INDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() },
		{ StatisticType::UNKNOWN, WeatherStatistic() }
	})
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

void StatsDisplay::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	bool inDoors = (typeid(WeatherData<false>) == typeid(updateInitiator));
	bool outDoors = (typeid(WeatherData<true>) == typeid(updateInitiator));

	auto& stats = m_statistics[((inDoors)
			? StatisticType::INDOORS
			: (outDoors) ? StatisticType::OUTDOORS
						 : StatisticType::UNKNOWN)];
	StatsUpdate(stats, data);
}
