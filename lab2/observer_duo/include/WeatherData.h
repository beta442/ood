#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "Observer.h"

enum class SensorType
{
	OUTDOORS,
	INDOORS,
};

struct WeatherInfo
{
	SensorType sensorType = SensorType::INDOORS;

	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class WeatherData : public Observable<WeatherInfo>
{
public:
	WeatherData(SensorType sensorType);

	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;
	SensorType GetSensorType() const;

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure);

protected:
	WeatherInfo GetChangedData() const override;

private:
	SensorType m_sensorType;

	double m_temperature;
	double m_humidity;
	double m_pressure;
};

#endif // !WEATHERDATA_H
