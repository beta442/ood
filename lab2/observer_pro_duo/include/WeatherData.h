#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"

struct WindInfo
{
	unsigned short windSpeed = 0;
	double windAngle = 0;
};

struct WeatherInfo
{
	double temperature = 0;
	double humidity = 760;
	double pressure = 0;
};

struct WeatherWindInfo
{
	WindInfo windInfo;
	WeatherInfo weatherInfo;
};

class WeatherData : public Observable<WeatherWindInfo>
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
	WeatherWindInfo GetChangedData() const override;

private:
	WeatherInfo m_weatherInfo;
};

class WeatherDataPro : public Observable<WeatherWindInfo>
{
public:
	WeatherDataPro();

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	WeatherInfo GetWeatherInfo() const;
	WindInfo GetWindInfo() const;

	void MeasurementsChanged();

	void SetMeasurements(const WeatherWindInfo& info);

protected:
	WeatherWindInfo GetChangedData() const override;

private:
	WeatherWindInfo m_weatherWindInfo;
};

#endif // !WEATHERDATA_H
