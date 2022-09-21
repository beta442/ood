#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay : public IObserver<WeatherWindInfo>
{
public:
	StatsDisplay(Observable<WeatherWindInfo>& indoorsStation, Observable<WeatherWindInfo>& outdoorsStation);
	~StatsDisplay();

private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;

	IObservable<WeatherWindInfo>* m_indoorsStation;
	IObservable<WeatherWindInfo>* m_outdoorsStation;

	IStatisticValueHolder<double>* m_humidityStatHolder;
	IStatisticValueHolder<double>* m_pressureStatHolder;
	IStatisticValueHolder<double>* m_temperatureStatHolder;

	IStatisticValueHolder<double>* m_windAngleHolder;
	IStatisticValueHolder<unsigned short>* m_windSpeedHolder;
};

#endif // !STATSDISPLAY_H
