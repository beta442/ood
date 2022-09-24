#ifndef DISPLAY_H
#define DISPLAY_H

#include "../include/Observer.h"
#include "../include/WeatherData.hpp"

class Display : public IObserver<WeatherInfo>
{
public:
	Display(const IObservable<WeatherInfo>& inDoors, const IObservable<WeatherInfo>& outDoors);

private:
	using ObserverType = const IObservable<WeatherInfo>*;

	void Update(const WeatherInfo& data, IObservable<WeatherInfo>& updateInitiator) override;

	ObserverType m_inDoors, m_outDoors;
};

#endif // !DISPLAY_H
