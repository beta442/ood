#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"

struct WindInfo
{
	double speed = 0;
	double angle = 0;
};

struct WeatherInfo
{
	WeatherInfo() = default;

	WeatherInfo(double temperature, double humidity, double pressure)
		: temperature(temperature)
		, humidity(humidity)
		, pressure(pressure)
	{
	}

	double temperature;
	double humidity;
	double pressure;
};

struct WeatherWindInfo
{
	WeatherWindInfo()
		: windInfo()
		, weatherInfo()
	{
	}

	WeatherWindInfo(double windSpeed, double windAngle, double temperature, double humidity, double pressure)
		: weatherInfo({ temperature, humidity, pressure })
		, windInfo({ windSpeed, windAngle })
	{
	}

	double GetHumidity() const
	{
		return weatherInfo.humidity;
	}

	double GetTemperature() const
	{
		return weatherInfo.temperature;
	}

	double GetPressure() const
	{
		return weatherInfo.pressure;
	}

	double GetWindSpeed() const
	{
		return windInfo.speed;
	}

	double GetWindAngle() const
	{
		return windInfo.angle;
	}

	WindInfo windInfo;
	WeatherInfo weatherInfo;
};

enum class WeatherDataStationType
{
	INDOORS = 0,
	OUTDOORS,
};

template <bool HasWindSensors = true>
class WeatherData : public Observer::Observable<WeatherWindInfo>
{
public:
	using MyBase = Observer::Observable<WeatherWindInfo>;

	WeatherData()
		: MyBase(std::move(WeatherWindInfo()))
	{
	}

	void SetMeasurements(const WeatherWindInfo& info)
	{
		m_signallingValue.SetValue(info);
	}

	void SetMeasurements(const WeatherInfo& info)
	{
		auto fullInfo = WeatherWindInfo();
		fullInfo.weatherInfo = info;

		m_signallingValue.SetValue(fullInfo);
	}
};

#endif // !WEATHERDATA_H
