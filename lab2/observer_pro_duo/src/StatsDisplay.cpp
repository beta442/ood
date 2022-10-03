#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay(const IObservable<WeatherWindInfo>& inDoors, const IObservable<WeatherWindInfo>& outDoors)
	: m_statistics({ { StatisticType::INDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() } })
	, m_inDoors(&inDoors)
	, m_outDoors(&outDoors)
{
}

void StatsDisplay::StatsUpdate(WeatherStatistic& stats, const WeatherWindInfo& data)
{
	stats.humidityStatHolder->TakeNextValue(data.weatherInfo.humidity);
	stats.pressureStatHolder->TakeNextValue(data.weatherInfo.pressure);
	stats.temperatureStatHolder->TakeNextValue(data.weatherInfo.temperature);

	stats.windAngleHolder->TakeNextValue(data.windInfo.windAngle);
	stats.windSpeedHolder->TakeNextValue(data.windInfo.windSpeed);
}

void StatsDisplay::Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource)
{
	bool isInDoors = &updateSource == m_inDoors;
	bool isOutDoors = &updateSource == m_outDoors;

	auto& stats = m_statistics[((isInDoors)
			? StatisticType::INDOORS
			: (isOutDoors) ? StatisticType::OUTDOORS
						 : StatisticType::UNKNOWN)];
	StatsUpdate(stats, data);

	std::cout << "Humidity:\n"
			  << StatHolderToString(*(stats.humidityStatHolder))
			  << "Pressure:\n"
			  << StatHolderToString(*(stats.pressureStatHolder))
			  << "Temperature:\n"
			  << StatHolderToString(*(stats.temperatureStatHolder))
			  << ((isOutDoors)
						 ? ("Wind angle:\n"
							 + WindAngleStatHolderToString(*(stats.windAngleHolder))
							 + "Wind speed:\n"
							 + StatHolderToString(*(stats.windSpeedHolder))
							 + '\n')
						 : "");
}
