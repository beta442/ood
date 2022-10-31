#ifndef ROBOT_ROBOT_H_
#define ROBOT_ROBOT_H_

#include <map>
#include <optional>
#include <ostream>
#include <string>

namespace robot
{

enum class WalkDirection
{
	North,
	South,
	West,
	East,
};

class Robot
{
public:
	Robot(std::ostream& outputEcho)
		: m_outputEcho(outputEcho)
	{
	}

	void TurnOn()
	{
		if (!m_turnedOn)
		{
			m_turnedOn = true;
			m_outputEcho << "It am waiting for your commands\n";
		}
	}

	void TurnOff()
	{
		if (m_turnedOn)
		{
			m_turnedOn = false;
			m_direction.reset();
			m_outputEcho << "It is a pleasure to serve you\n";
		}
	}

	void Walk(WalkDirection direction)
	{
		if (!m_turnedOn)
		{
			m_outputEcho << "The robot should be turned on first" << std::endl;
			return;
		}

		m_direction = direction;
		static const std::map<WalkDirection, std::string> directionToString = {
			{ WalkDirection::East, "east" },
			{ WalkDirection::South, "south" },
			{ WalkDirection::West, "west" },
			{ WalkDirection::North, "north" },
		};
		m_outputEcho << "Walking " << directionToString.at(direction) << std::endl;
	}

	void Stop()
	{
		if (!m_turnedOn)
		{
			m_outputEcho << "The robot should be turned on first" << std::endl;
			return;
		}

		if (m_direction)
		{
			m_direction.reset();
			m_outputEcho << "Stopped\n";
		}
		else
		{
			m_outputEcho << "I am staying still\n";
		}
	}

private:
	std::ostream& m_outputEcho;

	bool m_turnedOn = false;
	std::optional<WalkDirection> m_direction;
};

}; // namespace robot

#endif // !ROBOT_ROBOT_H_
