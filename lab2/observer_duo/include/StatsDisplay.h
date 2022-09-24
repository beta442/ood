#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include <map>
#include <memory>

#include "Observer.h"

#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay : public IObserver<WeatherInfo>
{
public:
	StatsDisplay(const IObservable<WeatherInfo>& inDoors, const IObservable<WeatherInfo>& outDoors);

private:
	using ObserverType = const IObservable<WeatherInfo>*;

	void Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateInitiator) override;

	struct WeatherStatistic;
	void StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data);

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
		{
		}

		std::shared_ptr<StatisticValueHolder<double>> humidityStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> pressureStatHolder;
		std::shared_ptr<StatisticValueHolder<double>> temperatureStatHolder;
	};

	std::map<StatisticType, WeatherStatistic> m_statistics;
	ObserverType m_inDoors, m_outDoors;
};

#endif // !STATSDISPLAY_H
