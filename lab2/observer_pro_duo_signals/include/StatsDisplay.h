#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include <map>
#include <memory>

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay : public IObserver<WeatherWindInfo>
{
public:
	StatsDisplay();

private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;

	struct WeatherStatistic;
	void StatsUpdate(WeatherStatistic& stats, const WeatherWindInfo& data);

	enum class StatisticType
	{
		INDOORS = 0,
		OUTDOORS,
		UNKNOWN,
	};

	struct WeatherStatistic
	{
		WeatherStatistic()
			: humidityStatHolder(std::make_shared<StatisticValueHolder<double>>())
			, pressureStatHolder(std::make_shared<StatisticValueHolder<double>>())
			, temperatureStatHolder(std::make_shared<StatisticValueHolder<double>>())
			, windAngleHolder(std::make_shared<WindAngleStatisticHolder>())
			, windSpeedHolder(std::make_shared<StatisticValueHolder<unsigned short>>())
		{
		}

		std::shared_ptr<StatisticValueHolder<double>> humidityStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> pressureStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> temperatureStatHolder;

		std::shared_ptr<WindAngleStatisticHolder> windAngleHolder;
		std::shared_ptr<StatisticValueHolder<unsigned short>> windSpeedHolder;
	};

	std::map<StatisticType, WeatherStatistic> m_statistics;
};

#endif // !STATSDISPLAY_H
