#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo>
{
public:
	StatsDisplay();
	~StatsDisplay();

private:
	void Update(const WeatherInfo& data, const IObservable<WeatherInfo>& updateSource) override;

	StatisticValueHolder<double>* m_humidityStatHolder;
	StatisticValueHolder<double>* m_pressureStatHolder;
	StatisticValueHolder<double>* m_temperatureStatHolder;

	WindAngleStatisticHolder* m_windAngleHolder;
	StatisticValueHolder<double>* m_windSpeedHolder;
};

#endif // !STATSDISPLAY_H
