#ifndef STATSDISPLAY_H
#define STATSDISPLAY_H

#include "Observer.h"
#include "StatisticValueHolder.hpp"
#include "WeatherData.h"

class StatsDisplay : public IObserver<WeatherInfo>
{
public:
	StatsDisplay();

private:
	void Update(const WeatherInfo& data) override;

	StatisticValueHolder<double> m_humidityStatHolder;
	StatisticValueHolder<double> m_pressureStatHolder;
	StatisticValueHolder<double> m_temperatureStatHolder;
};

#endif // !STATSDISPLAY_H
