#include "../include/WeatherData.h"

#include <map>
#include <vector>

constexpr std::string_view UNKNOWN_EVENT_TYPE = "Unknown";
constexpr std::string_view ON_UPDATE_EVENT_TYPE = "OnUpdate";
constexpr std::string_view ON_WEATHER_UPDATE_EVENT_TYPE = "OnWeatherUpdate";
constexpr std::string_view ON_WIND_UPDATE_EVENT_TYPE = "OnWindUpdate";
constexpr std::string_view ON_TEMPERATURE_UPDATE_EVENT_TYPE = "OnTemperatureUpdate";
constexpr std::string_view ON_HUMIDITY_UPDATE_EVENT_TYPE = "OnHumidityUpdate";
constexpr std::string_view ON_PRESSURE_UPDATE_EVENT_TYPE = "OnPressureUpdate";
constexpr std::string_view ON_WIND_SPEED_UPDATE_EVENT_TYPE = "OnWindSpeedUpdate";
constexpr std::string_view ON_WIND_ANGLE_UPDATE_EVENT_TYPE = "OnWindAngleUpdate";

const std::map<std::string_view, Event> EVENT_TYPE{
	{ UNKNOWN_EVENT_TYPE, Event(UNKNOWN_EVENT_TYPE) },
	{ ON_UPDATE_EVENT_TYPE, Event(ON_UPDATE_EVENT_TYPE) },
	{ ON_WEATHER_UPDATE_EVENT_TYPE, Event(ON_WEATHER_UPDATE_EVENT_TYPE) },
	{ ON_WIND_UPDATE_EVENT_TYPE, Event(ON_WIND_UPDATE_EVENT_TYPE) },
	{ ON_TEMPERATURE_UPDATE_EVENT_TYPE, Event(ON_TEMPERATURE_UPDATE_EVENT_TYPE) },
	{ ON_HUMIDITY_UPDATE_EVENT_TYPE, Event(ON_HUMIDITY_UPDATE_EVENT_TYPE) },
	{ ON_PRESSURE_UPDATE_EVENT_TYPE, Event(ON_PRESSURE_UPDATE_EVENT_TYPE) },
	{ ON_WIND_SPEED_UPDATE_EVENT_TYPE, Event(ON_WIND_SPEED_UPDATE_EVENT_TYPE) },
	{ ON_WIND_ANGLE_UPDATE_EVENT_TYPE, Event(ON_WIND_ANGLE_UPDATE_EVENT_TYPE) }
};

WeatherData::WeatherData()
	: m_weatherWindInfo()
	, m_updateEventTypes()
{
}

double WeatherData::GetTemperature() const
{
	return m_weatherWindInfo.weatherInfo.temperature;
}

double WeatherData::GetHumidity() const
{
	return m_weatherWindInfo.weatherInfo.humidity;
}

double WeatherData::GetPressure() const
{
	return m_weatherWindInfo.weatherInfo.pressure;
}

WeatherInfo WeatherData::GetWeatherInfo() const
{
	return m_weatherWindInfo.weatherInfo;
}

WindInfo WeatherData::GetWindInfo() const
{
	return m_weatherWindInfo.windInfo;
}

std::vector<Event> WeatherData::GetUpdateEvents(const WeatherWindInfo& newInfo)
{
	std::vector<Event> res;
	res.reserve(EVENT_TYPE.size());

	if (m_weatherWindInfo.weatherInfo != newInfo.weatherInfo)
	{
		res.emplace_back(EVENT_TYPE.at(ON_WEATHER_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.windInfo != newInfo.windInfo)
	{
		res.emplace_back(EVENT_TYPE.at(ON_WIND_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.weatherInfo.humidity != newInfo.weatherInfo.humidity)
	{
		res.emplace_back(EVENT_TYPE.at(ON_HUMIDITY_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.weatherInfo.pressure != newInfo.weatherInfo.pressure)
	{
		res.emplace_back(EVENT_TYPE.at(ON_PRESSURE_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.weatherInfo.temperature != newInfo.weatherInfo.temperature)
	{
		res.emplace_back(EVENT_TYPE.at(ON_TEMPERATURE_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.windInfo.windAngle != newInfo.windInfo.windAngle)
	{
		res.emplace_back(EVENT_TYPE.at(ON_WIND_ANGLE_UPDATE_EVENT_TYPE));
	}
	if (m_weatherWindInfo.windInfo.windSpeed != newInfo.windInfo.windSpeed)
	{
		res.emplace_back(EVENT_TYPE.at(ON_WIND_SPEED_UPDATE_EVENT_TYPE));
	}

	if (res.size() != 0)
	{
		res.emplace_back(EVENT_TYPE.at(ON_UPDATE_EVENT_TYPE));
	}
	return res;
}

void WeatherData::MeasurementsChanged()
{
	for (auto& _event : m_updateEventTypes)
	{
		NotifyObservers(_event);
	}
}

void WeatherData::SetMeasurements(const WeatherWindInfo& info)
{
	m_updateEventTypes = GetUpdateEvents(info);
	m_weatherWindInfo = info;

	MeasurementsChanged();
}

 WeatherWindInfo WeatherData::GetChangedData() const
{
	WeatherWindInfo info;
	info.weatherInfo = GetWeatherInfo();
	info.windInfo = GetWindInfo();
	return info;
 }
