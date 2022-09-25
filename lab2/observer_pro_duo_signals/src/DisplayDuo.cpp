#include "../include/pch.h"

#include "../include/DisplayDuo.h"

constexpr auto OnWeatherChange(WeatherDataStationType wdStationType)
{
	return [=, stationType = wdStationType](auto& _, auto& currWeatherInfo) noexcept {
		bool isSourceOutDoors = (wdStationType == WeatherDataStationType::OUTDOORS);
		std::cout << "WeatherInfo source type:\n"
				  << ((stationType == WeatherDataStationType::INDOORS)
							 ? "INDOORS"
							 : (isSourceOutDoors)
							 ? "OUTDOORS"
							 : "UNKNOWN")
				  << '\n';

		std::cout << "Current Temp: " << currWeatherInfo.GetTemperature() << '\n'
				  << "Current Hum: " << currWeatherInfo.GetHumidity() << '\n'
				  << "Current Pressure: " << currWeatherInfo.GetPressure() << '\n';

		if (isSourceOutDoors)
		{
			std::cout << "Current Wind angle: " << currWeatherInfo.GetWindAngle() << '\n'
					  << "Current Wind speed: " << currWeatherInfo.GetWindSpeed() << '\n';
		}
		std::cout << "----------------" << '\n';
	};
};

DisplayDuo::DisplayDuo(WeatherInfoStation& stationIn, WeatherInfoStation& stationOut)
{
	stationIn.Connect(OnWeatherChange(WeatherDataStationType::INDOORS));
	stationOut.Connect(OnWeatherChange(WeatherDataStationType::OUTDOORS));
}
