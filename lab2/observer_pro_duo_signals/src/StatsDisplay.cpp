#include "../include/pch.h"

#include "../include/StatsDisplay.h"

#include "../include/StatisticValueHolder.hpp"

struct WeatherStatistic
{
	WeatherStatistic()
		: humidityStatHolder(std::make_shared<StatisticValueHolder<double>>())
		, pressureStatHolder(std::make_shared<StatisticValueHolder<double>>())
		, temperatureStatHolder(std::make_shared<StatisticValueHolder<double>>())
		, windAngleHolder(std::make_shared<WindAngleStatisticHolder>())
		, windSpeedHolder(std::make_shared<StatisticValueHolder<double>>())
	{
	}

	std::shared_ptr<StatisticValueHolder<double>> humidityStatHolder;
	std::shared_ptr<StatisticValueHolder<double>> pressureStatHolder;
	std::shared_ptr<StatisticValueHolder<double>> temperatureStatHolder;

	std::shared_ptr<WindAngleStatisticHolder> windAngleHolder;
	std::shared_ptr<StatisticValueHolder<double>> windSpeedHolder;
};

void StatsUpdate(WeatherStatistic& stats, const WeatherWindInfo& data)
{
	stats.humidityStatHolder->TakeNextValue(data.GetHumidity());
	stats.pressureStatHolder->TakeNextValue(data.GetPressure());
	stats.temperatureStatHolder->TakeNextValue(data.GetTemperature());

	stats.windAngleHolder->TakeNextValue(data.GetWindAngle());
	stats.windSpeedHolder->TakeNextValue(data.GetWindSpeed());
}

const auto OnWeatherInfoChange(WeatherDataStationType wdStationType)
{
	return [=, weatherStats = WeatherStatistic(), wdType = wdStationType](auto& _, auto newWeatherInfo) mutable noexcept {
		StatsUpdate(weatherStats, newWeatherInfo);

		bool isSourceOutDoors = (wdStationType == WeatherDataStationType::OUTDOORS);
		std::cout << "WeatherInfo source type:\n"
				  << ((wdStationType == WeatherDataStationType::INDOORS)
							 ? "INDOORS"
							 : (isSourceOutDoors)
							 ? "OUTDOORS"
							 : "UNKNOWN")
				  << '\n';

		std::cout << "Humidity:\n"
				  << StatHolderToString(*(weatherStats.humidityStatHolder))
				  << "Pressure:\n"
				  << StatHolderToString(*(weatherStats.pressureStatHolder))
				  << "Temperature:\n"
				  << StatHolderToString(*(weatherStats.temperatureStatHolder))
				  << ((isSourceOutDoors)
							 ? ("Wind angle:\n"
								 + StatHolderToString(*(weatherStats.windAngleHolder))
								 + "Wind speed:\n"
								 + StatHolderToString(*(weatherStats.windSpeedHolder))
								 + '\n')
							 : "");
	};
}

StatsDisplay::StatsDisplay(WeatherInfoStation& stationIn, WeatherInfoStation& stationOut)
{
	stationIn.Connect(OnWeatherInfoChange(WeatherDataStationType::INDOORS));
	stationOut.Connect(OnWeatherInfoChange(WeatherDataStationType::OUTDOORS));
}
