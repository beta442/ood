#include "../include/WeatherData.h"

WeatherData::WeatherData()
	: m_temperature(0.0)
	, m_humidity(0.0)
	, m_pressure(760.0)
{
}

double WeatherData::GetTemperature() const
{
	return m_temperature;
}

double WeatherData::GetHumidity() const
{
	return m_humidity;
}

double WeatherData::GetPressure() const
{
	return m_pressure;
}

WindInfo WeatherData::GetWindInfo() const
{
	return m_windInfo;
}

void WeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

constexpr auto MAX_ANGLE = 360;

unsigned short ValidateWindAngle(unsigned short angle)
{
	return angle % MAX_ANGLE;
}

void WeatherData::SetMeasurements(const WeatherInfo& info)
{
	m_windInfo.windAngle = ValidateWindAngle(info.windInfo.windAngle);
	m_windInfo.windSpeed = info.windInfo.windSpeed;

	m_humidity = info.humidity;
	m_temperature = info.temperature;
	m_pressure = info.pressure;

	MeasurementsChanged();
}

WeatherInfo WeatherData::GetChangedData() const
{
	WeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();
	info.windInfo = GetWindInfo();
	return info;
}
