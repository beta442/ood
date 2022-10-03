#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "EventHolder.hpp"
#include "StatisticValueHolder.hpp"
#include "WeatherData.hpp"

class StatsDisplay
{
public:
	StatsDisplay(IEventInitiator* weatherData);
	~StatsDisplay();

private:
	void UpdateStatistics(const WeatherWindInfo& info);

	StatisticValueHolder<double>* m_humidityStatHolder;
	StatisticValueHolder<double>* m_pressureStatHolder;
	StatisticValueHolder<double>* m_temperatureStatHolder;

	WindAngleStatisticHolder* m_windAngleHolder;
	StatisticValueHolder<double>* m_windSpeedHolder;

	Unsubscriber m_unsubscriber;
};

#endif // !STATSDISPLAY_H
