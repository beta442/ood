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
			m_weatherSignal.SetValue(std::forward<WeatherInfo>(weatherInfo));
		}
		if constexpr (std::is_same<WindInfo, Info>::value)
		{
			fullInfo.windInfo = weatherInfo;
			m_windSignal.SetValue(std::forward<WindInfo>(weatherInfo));
		}
		if constexpr (std::is_same<WeatherWindInfo, Info>::value)
		{
			fullInfo = weatherInfo;
		}
		m_weatherWindSignal.SetValue(std::forward<WeatherWindInfo>(fullInfo));
	}

	Signal::Connection OnWindAngleChange(const Signal::SignallingValue<double>::Slot& onChange)
	{
		return m_windAngleSignal.Connect(onChange);
	}

	Signal::Connection OnWindSpeedChange(const Signal::SignallingValue<double>::Slot& onChange)
	{
		return m_windSpeedSignal.Connect(onChange);
	}

	Signal::Connection OnWeatherChange(const Signal::SignallingValue<WeatherInfo>::Slot& onChange)
	{
		return m_weatherSignal.Connect(onChange);
	}

	Signal::Connection OnWeatherWindChange(const Signal::SignallingValue<WeatherWindInfo>::Slot& onChange)
	{
		return m_weatherWindSignal.Connect(onChange);
	}

	Signal::Connection OnWindChange(const Signal::SignallingValue<WindInfo>::Slot& onChange)
	{
		return m_windSignal.Connect(onChange);
	}

private:
	Signal::SignallingValue<double> m_windAngleSignal{};
	Signal::SignallingValue<double> m_windSpeedSignal{};

	Signal::SignallingValue<WeatherInfo> m_weatherSignal{};
	Signal::SignallingValue<WeatherWindInfo> m_weatherWindSignal{};
	Signal::SignallingValue<WindInfo> m_windSignal{};
};

#endif // !WEATHERDATA_H
