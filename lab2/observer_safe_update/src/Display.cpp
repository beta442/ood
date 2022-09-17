#include <algorithm>

#include "../include/pch.h"

#include "../include/Display.h"

void Display::Update(const WeatherInfo& data)
{
	for (auto it = std::begin(m_observables), end = std::end(m_observables); it != end; ++it)
	{
		if ((*it)->RemoveObserver(*this))
		{
			break;
		}
	}

	std::cout << "Current Temp " << data.temperature << std::endl;
	std::cout << "Current Hum " << data.humidity << std::endl;
	std::cout << "Current Pressure " << data.pressure << std::endl;
	std::cout << "----------------" << std::endl;
}

