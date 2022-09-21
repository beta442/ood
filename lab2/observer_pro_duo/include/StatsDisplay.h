#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay : public IObserver<WeatherWindInfo>
{
public:
	StatsDisplay();
	~StatsDisplay();

private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;

	IStatisticValueHolder<double>* m_humidityStatHolder;
	IStatisticValueHolder<double>* m_pressureStatHolder;
	IStatisticValueHolder<double>* m_temperatureStatHolder;

	IStatisticValueHolder<double>* m_windAngleHolder;
	IStatisticValueHolder<unsigned short>* m_windSpeedHolder;
};

#endif // !STATSDISPLAY_H
