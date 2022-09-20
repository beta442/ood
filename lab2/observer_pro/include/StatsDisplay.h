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

	IStatisticValueHolder<double>* m_humidityStatHolder;
	IStatisticValueHolder<double>* m_pressureStatHolder;
	IStatisticValueHolder<double>* m_temperatureStatHolder;

	IStatisticValueHolder<double>* m_windAngleHolder;
	IStatisticValueHolder<unsigned short>* m_windSpeedHolder;
};

#endif // !STATSDISPLAY_H
