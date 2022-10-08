#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "SignallingValue.hpp"

struct WindInfo
{
	double speed = 0;
	double angle = 0;
};

struct WeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

struct WeatherWindInfo
{
	WindInfo windInfo{};
	WeatherInfo weatherInfo{};
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
		m_weatherWindSignal.SetValue(std::forward<WeatherWindInfo>(fullInfo));
	}

	Signal::Connection OnWeatherWindChange(const Signal::SignallingValue<WeatherWindInfo>::Slot& onChange)
	{
		return m_weatherWindSignal.Connect(onChange);
	}

private:
	Signal::SignallingValue<WeatherWindInfo> m_weatherWindSignal{};
};

#endif // !WEATHERDATA_H
