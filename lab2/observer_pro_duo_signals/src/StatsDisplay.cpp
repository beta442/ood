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
	stats.humidityStatHolder->TakeNextValue(data.weatherInfo.humidity);
	stats.pressureStatHolder->TakeNextValue(data.weatherInfo.pressure);
	stats.temperatureStatHolder->TakeNextValue(data.weatherInfo.pressure);

	stats.windAngleHolder->TakeNextValue(data.windInfo.angle);
	stats.windSpeedHolder->TakeNextValue(data.windInfo.speed);
}

auto onWeatherChange{
	[weatherStats = WeatherStatistic()](auto& _, auto& newWeatherInfo) mutable noexcept {
		std::cout << "INDOORS\n";

		StatsUpdate(weatherStats, newWeatherInfo);

		std::cout << "Humidity:\n"
				  << StatHolderToString(*(weatherStats.humidityStatHolder))
				  << "Pressure:\n"
				  << StatHolderToString(*(weatherStats.pressureStatHolder))
				  << "Temperature:\n"
				  << StatHolderToString(*(weatherStats.temperatureStatHolder))
				  << "---------------------------------------------\n";
	}
};

auto onWeatherWindChange{
	[weatherStats = WeatherStatistic()](auto& _, auto& newWeatherWindInfo) mutable noexcept {
		std::cout << "OUTDOORS\n";

		StatsUpdate(weatherStats, newWeatherWindInfo);

		std::cout << "Humidity:\n"
				  << StatHolderToString(*(weatherStats.humidityStatHolder))
				  << "Pressure:\n"
				  << StatHolderToString(*(weatherStats.pressureStatHolder))
				  << "Temperature:\n"
				  << StatHolderToString(*(weatherStats.temperatureStatHolder))
				  << "Wind angle:\n"
				  << WindAngleStatHolderToString(*(weatherStats.windAngleHolder))
				  << "Wind speed:\n"
				  << StatHolderToString(*(weatherStats.windSpeedHolder))
				  << "---------------------------------------------\n";
	}
};

StatsDisplay::StatsDisplay(WeatherData* stationIn, WeatherData* stationOut)
{
	m_connectionStationIn = stationIn->OnWeatherWindChange(onWeatherChange);
	m_connectionStationOut = stationOut->OnWeatherWindChange(onWeatherWindChange);
}

StatsDisplay::~StatsDisplay()
{
	m_connectionStationIn.disconnect();
	m_connectionStationOut.disconnect();
}
