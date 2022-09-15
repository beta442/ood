#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include <map>

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.h"

class StatsDisplay : public AbstractObserver<WeatherInfo>
{
public:
	StatsDisplay(Observable* indoorsWD, Observable* outdoorsWD);

private:
	void Update(const WeatherInfo& data, Observable& updateInitiator) override;

	struct WeatherStatistic
	{
		StatisticValueHolder<double> m_humidityStatHolder;
		StatisticValueHolder<double> m_pressureStatHolder;
		StatisticValueHolder<double> m_temperatureStatHolder;
	};

	void StatsUpdate(WeatherStatistic& stats, const WeatherInfo& data);

	std::map<Observable*, WeatherStatistic> m_updaterToStatisticMap;
};

#endif // !STATSDISPLAY_H
