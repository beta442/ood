#ifndef DISPLAYDUO_H
#define DISPLAYDUO_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class DisplayDuo : public IObserver<WeatherWindInfo>
{
public:
	DisplayDuo(const IObservable<WeatherWindInfo>& inDoors, const IObservable<WeatherWindInfo>& outDoors);

private:
	using ObservableType = const IObservable<WeatherWindInfo>*;

	void Update(const WeatherWindInfo& data, IObservable<WeatherWindInfo>& updateSource) override;

	ObservableType m_inDoors, m_outDoors;
};

#endif // !DISPLAYDUO_H
