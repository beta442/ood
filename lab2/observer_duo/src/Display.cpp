#include <algorithm>

#include "../include/pch.h"

#include "../include/Display.h"

Display::Display(Observable* indoorsWD, Observable* outdoorsWD)
	: m_indoorsWD(indoorsWD)
	, m_outdoorsWD(outdoorsWD)
{
	m_indoorsWD->RegisterObserver(*this);
	m_outdoorsWD->RegisterObserver(*this);
}

void Display::Update(const WeatherInfo& data, Observable& updateInitiator)
{
	std::cout << ((&updateInitiator == m_indoorsWD)
			? "INDOORS"
			: (&updateInitiator == m_outdoorsWD) ? "OUTDOORS"
												 : "UNKNOWN SOURCE")
			  << ":\n";

	std::cout << "Current Temp " << data.temperature << '\n';
	std::cout << "Current Hum " << data.humidity << '\n';
	std::cout << "Current Pressure " << data.pressure << '\n';
	std::cout << "----------------" << '\n';
}
