#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "EventHolder.hpp"

struct WindInfo
{
	WindInfo() = default;
	WindInfo(unsigned short windSpeed, double windAngle)
		: windSpeed(windSpeed)
		, windAngle(windAngle)
	{
	}

	double windSpeed = 0;
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

	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

struct WeatherWindInfo
{
	WeatherWindInfo()
		: windInfo()
		, weatherInfo()
	{
	}

	WeatherWindInfo(unsigned short windSpeed, double angle, double temperature, double humidity, double pressure)
		: weatherInfo(temperature, humidity, pressure)
		, windInfo(windSpeed, angle)
	{
	}


	WeatherInfo weatherInfo{};
	WindInfo windInfo{};
};

class WeatherData
{
public:
	WeatherData() = default;

	template <typename Info = WeatherWindInfo>
	void SetMeasurements(Info&& weatherInfo)
	{
		WeatherWindInfo fullInfo;
		if constexpr (std::is_same<WeatherInfo, Info>::value)
		{
			fullInfo.weatherInfo = weatherInfo;
		}
		if constexpr (std::is_same<WindInfo, Info>::value)
		{
			fullInfo.windInfo = weatherInfo;
		}
		if constexpr (std::is_same<WeatherWindInfo, Info>::value)
		{
			fullInfo = weatherInfo;
		}
		m_weatherWindInfo = fullInfo;
		EventHolder<Info>::NotifyListeners(std::forward<Info>(weatherInfo));
	}

private:
	WeatherWindInfo m_weatherWindInfo;
};

#endif // !WEATHERDATA_H
