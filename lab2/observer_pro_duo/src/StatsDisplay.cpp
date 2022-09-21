#include "../include/pch.h"

#include "../include/StatsDisplay.h"

StatsDisplay::StatsDisplay()
	: m_statistics({
		{ StatisticType::INDOORS, WeatherStatistic() },
		{ StatisticType::OUTDOORS, WeatherStatistic() }
	})
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

void StatsDisplay::Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource)
{
	bool inDoors = (typeid(WeatherData<false>) == typeid(updateSource));
	bool outDoors = (typeid(WeatherData<true>) == typeid(updateSource));

	auto& stats = m_statistics[((inDoors) ? StatisticType::INDOORS : StatisticType::OUTDOORS)];
	StatsUpdate(m_statistics[((inDoors) ? StatisticType::INDOORS : StatisticType::OUTDOORS)], data);

	std::cout << "Humidity:\n"
			  << StatHolderToString(*(stats.humidityStatHolder))
			  << "Pressure:\n"
			  << StatHolderToString(*(stats.pressureStatHolder))
			  << "Temperature:\n"
			  << StatHolderToString(*(stats.temperatureStatHolder))
			  << ((!inDoors && outDoors)
		? ("Wind angle:\n" + StatHolderToString(*(stats.windAngleHolder)) +
			"Wind speed:\n" + StatHolderToString(*(stats.windSpeedHolder)) + '\n')
		: "");
}
