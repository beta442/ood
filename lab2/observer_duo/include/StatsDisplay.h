#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include <map>
#include <memory>

#include "Observer.h"

#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay : public AbstractObserver<WeatherInfo>
{
public:
	StatsDisplay();

private:
	void Update(const WeatherInfo& data, Observable& updateInitiator) override;

	struct WeatherStatistic;
	void StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data);

	enum class StatisticType
	{
		INDOORS = 0,
		OUTDOORS,
	};

	struct WeatherStatistic
	{
		WeatherStatistic()
			: humidityStatHolder(std::make_shared<StatisticValueHolder<double>>())
			, pressureStatHolder(std::make_shared<StatisticValueHolder<double>>())
			, temperatureStatHolder(std::make_shared<StatisticValueHolder<double>>())
		{
		}

		std::shared_ptr<StatisticValueHolder<double>> humidityStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> pressureStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> temperatureStatHolder;
	};

	std::map<StatisticType, WeatherStatistic> m_statistics;
};

#endif // !STATSDISPLAY_H
