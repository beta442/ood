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
	WeatherWindInfo() = default;

	WeatherWindInfo(unsigned short windSpeed, double angle, double temperature, double humidity, double pressure)
		: weatherInfo({temperature, humidity, pressure})
		, windInfo({windSpeed, angle})
	{
	}

	WindInfo windInfo;
	WeatherInfo weatherInfo;
};

template <bool HasWindSensors = true>
class WeatherData : public Observable<WeatherWindInfo>
{
public:
	WeatherData()
		: m_weatherInfo()
	{
	}

	double GetTemperature() const
	{
		return m_weatherInfo.weatherInfo.temperature;
	}

	double GetHumidity() const
	{
		return m_weatherInfo.weatherInfo.humidity;
	}

	double GetPressure() const
	{
		return m_weatherInfo.weatherInfo.pressure;
	}

	WeatherInfo GetWeatherInfo() const
	{
		return m_weatherInfo.weatherInfo;
	}

	WindInfo GetWindInfo() const
	{
		if constexpr (HasWindSensors)
		{
			return m_weatherInfo.windInfo;
		}
		else
		{
			return WindInfo();
		}
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(const WeatherWindInfo& info)
	{
		m_weatherInfo = info;

		MeasurementsChanged();
	}

	void SetMeasurements(const WeatherInfo& info)
	{
		m_weatherInfo.weatherInfo = info;

		MeasurementsChanged();
	}

protected:
	WeatherWindInfo GetChangedData() const override
	{
		WeatherWindInfo info{};
		
		info.weatherInfo = GetWeatherInfo();
		if constexpr (HasWindSensors)
		{
			info.windInfo = GetWindInfo();
		}
		return info;
	}

private:
	WeatherWindInfo m_weatherInfo;
};

#endif // !WEATHERDATA_H
