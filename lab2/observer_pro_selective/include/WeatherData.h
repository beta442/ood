#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <vector>

#include "Observer.h"

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
		return (windSpeed == other.windSpeed) && (windAngle == other.windAngle);
	}

	bool operator!=(const WindInfo& other) const
	{
		return !(*this == other);
	}

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

	bool operator==(const WeatherInfo& other) const
	{
		return (temperature == other.temperature) && (humidity == other.humidity) && (pressure == other.pressure);
	}

	bool operator!=(const WeatherInfo& other) const
	{
		return !(*this == other);
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

class WeatherData : public Observable<WeatherWindInfo>
{
public:
	WeatherData();

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
	std::vector<Event> GetUpdateEvents(const WeatherWindInfo& newInfo);

	WeatherWindInfo m_weatherWindInfo;
	std::vector<Event> m_updateEventTypes;
};

constexpr std::string_view UNKNOWN_EVENT_TYPE = "Unknown";
constexpr std::string_view ON_UPDATE_EVENT_TYPE = "OnUpdate";
constexpr std::string_view ON_WEATHER_UPDATE_EVENT_TYPE = "OnWeatherUpdate";
constexpr std::string_view ON_WIND_UPDATE_EVENT_TYPE = "OnWindUpdate";
constexpr std::string_view ON_TEMPERATURE_UPDATE_EVENT_TYPE = "OnTemperatureUpdate";
constexpr std::string_view ON_HUMIDITY_UPDATE_EVENT_TYPE = "OnHumidityUpdate";
constexpr std::string_view ON_PRESSURE_UPDATE_EVENT_TYPE = "OnPressureUpdate";
constexpr std::string_view ON_WIND_SPEED_UPDATE_EVENT_TYPE = "OnWindSpeedUpdate";
constexpr std::string_view ON_WIND_ANGLE_UPDATE_EVENT_TYPE = "OnWindAngleUpdate";

#endif // !WEATHERDATA_H
