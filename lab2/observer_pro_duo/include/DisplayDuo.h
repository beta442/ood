#ifndef DISPLAYDUO_H
#define DISPLAYDUO_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class DisplayDuo : public IObserver<WeatherWindInfo>
{
public:
	DisplayDuo(Observable<WeatherWindInfo>& indoorsStation, Observable<WeatherWindInfo>& outdoorsStation);

private:
	void Update(const WeatherWindInfo& data, const IObservable<WeatherWindInfo>& updateSource) override;

	IObservable<WeatherWindInfo>* m_indoorsStation;
	IObservable<WeatherWindInfo>* m_outdoorsStation;
};

#endif // !DISPLAYDUO_H
