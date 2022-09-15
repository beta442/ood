#ifndef DISPLAY_H
#define DISPLAY_H

#include "../include/Observer.h"
#include "../include/WeatherData.h"

class Display : public AbstractObserver<WeatherInfo>
{
public:
	Display(Observable* indoorsWD, Observable* outdoorsWD);

private:
	void Update(const WeatherInfo& data, Observable& updateInitiator) override;

	Observable* m_indoorsWD;
	Observable* m_outdoorsWD;
};

#endif // !DISPLAY_H
