#include <iostream>

#include "../include/WindSpeedDisplay.h"

constexpr auto onWindInfoChange{
	[](auto& data) {
		std::cout << "Current Wind speed " << data.windSpeed << '\n'
				  << "----------------" << '\n';
	}
};

WindSpeedDisplay::WindSpeedDisplay()
{
	EventHolder<WindInfo>::AddListener(onWindInfoChange);
}
