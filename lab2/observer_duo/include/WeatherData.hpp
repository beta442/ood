#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"

struct WeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class WeatherData : public Observable<WeatherInfo>
{
public:
	WeatherData()
		: m_temperature(0.0)
		, m_humidity(0.0)
		, m_pressure(760.0)
	{
	}

	double GetTemperature() const
	{
		return m_temperature;
	}

	double GetHumidity() const
	{
		return m_humidity;
	}

	double GetPressure() const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}

protected:
	WeatherInfo GetChangedData() const override
	{
		WeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}

private:
	double m_temperature;
	double m_humidity;
	double m_pressure;
};

#endif // !WEATHERDATA_H
