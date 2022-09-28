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

	bool operator==(const WindInfo& other) const
	{
		return (windAngle == other.windAngle) && (windSpeed == other.windSpeed);
	}
	bool operator!=(const WindInfo& other) const
	{
		return !(*this == other);
	}

	double windAngle = 0;
	double windSpeed = 0;
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

	bool operator==(const WeatherInfo& other) const
	{
		return (humidity == other.humidity) && (pressure == other.pressure) && (temperature == other.temperature);
	}
	bool operator!=(const WeatherInfo& other) const
	{
		return !(*this == other);
	}

	double humidity = 0;
	double pressure = 0;
	double temperature = 0;
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

	bool operator==(const WeatherWindInfo& other) const
	{
		return (weatherInfo == other.weatherInfo) && (windInfo == other.windInfo);
	}
	bool operator!=(const WeatherWindInfo& other) const
	{
		return !(*this == other);
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
			EventHolder<WeatherInfo>::NotifyListeners(std::forward<WeatherInfo>(weatherInfo));
		}
		if constexpr (std::is_same<WindInfo, Info>::value)
		{
			fullInfo.windInfo = weatherInfo;
			EventHolder<WindInfo>::NotifyListeners(std::forward<WindInfo>(weatherInfo));
		}
		if constexpr (std::is_same<WeatherWindInfo, Info>::value)
		{
			fullInfo = weatherInfo;
		}
		m_weatherWindInfo = fullInfo;
		EventHolder<WeatherWindInfo>::NotifyListeners(std::forward<WeatherWindInfo>(m_weatherWindInfo));
	}

private:
	WeatherWindInfo m_weatherWindInfo;
};

#endif // !WEATHERDATA_H
