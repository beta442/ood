#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "../../observer_full_stat/include/StatisticValueHolder.hpp"

#include "Observer.h"
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo>
{
public:
	StatsDisplay();

private:
	void Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateSource) override;

	StatisticValueHolder<double> m_humidityStatHolder;
	StatisticValueHolder<double> m_pressureStatHolder;
	StatisticValueHolder<double> m_temperatureStatHolder;
};

#endif // !STATSDISPLAY_H
