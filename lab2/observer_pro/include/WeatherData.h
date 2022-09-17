#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"

struct WindInfo
{
	unsigned short windSpeed = 0;
	unsigned short windAngle = 0;
};

struct WeatherInfo
{
	WindInfo windInfo{};

	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class WeatherData : public Observable<WeatherInfo>
{
public:
	WeatherData();

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;
	WindInfo GetWindInfo() const;

	void MeasurementsChanged();

	void SetMeasurements(const WeatherInfo& info);

protected:
	WeatherInfo GetChangedData() const override;

private:
	WindInfo m_windInfo;

	double m_temperature;
	double m_humidity;
	double m_pressure;
};

#endif // !WEATHERDATA_H
