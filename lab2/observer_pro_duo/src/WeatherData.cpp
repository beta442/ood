#include "../include/WeatherData.h"

WeatherData::WeatherData()
	: m_weatherInfo()
{
}

double WeatherData::GetTemperature() const
{
	return m_weatherInfo.temperature;
}

double WeatherData::GetHumidity() const
{
	return m_weatherInfo.humidity;
}

double WeatherData::GetPressure() const
{
	return m_weatherInfo.pressure;
}

void WeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void WeatherData::SetMeasurements(const WeatherInfo& info)
{
	m_weatherInfo  = info;

	MeasurementsChanged();
}

WeatherWindInfo WeatherData::GetChangedData() const
{
	WeatherWindInfo info;
	info.weatherInfo.temperature = GetTemperature();
	info.weatherInfo.humidity = GetHumidity();
	info.weatherInfo.pressure = GetPressure();
	return info;
}



WeatherDataPro::WeatherDataPro()
	: m_weatherWindInfo()
{
}

double WeatherDataPro::GetTemperature() const
{
	return m_weatherWindInfo.weatherInfo.temperature;
}

double WeatherDataPro::GetHumidity() const
{
	return m_weatherWindInfo.weatherInfo.humidity;
}

double WeatherDataPro::GetPressure() const
{
	return m_weatherWindInfo.weatherInfo.pressure;
}

WeatherInfo WeatherDataPro::GetWeatherInfo() const
{
	return m_weatherWindInfo.weatherInfo;
}

WindInfo WeatherDataPro::GetWindInfo() const
{
	return m_weatherWindInfo.windInfo;
}

void WeatherDataPro::MeasurementsChanged()
{
	NotifyObservers();
}

void WeatherDataPro::SetMeasurements(const WeatherWindInfo& info)
{
	m_weatherWindInfo = info;

	MeasurementsChanged();
}

WeatherWindInfo WeatherDataPro::GetChangedData() const
{
	WeatherWindInfo info;
	info.weatherInfo = GetWeatherInfo();
	info.windInfo = GetWindInfo();
	return info;
}
