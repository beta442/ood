//#include "../include/pch.h"
//
//#include "../include/Robot.h"
//
//using namespace robot;
//
//Robot::Robot(std::ostream& outputEcho)
//	: m_outputEcho(outputEcho)
//{
//}
//
//void Robot::TurnOn()
//{
//	if (!m_turnedOn)
//	{
//		m_turnedOn = true;
//		m_outputEcho << "It am waiting for your commands\n";
//	}
//}
//
//void Robot::TurnOff()
//{
//	if (m_turnedOn)
//	{
//		m_turnedOn = false;
//		m_direction.reset();
//		m_outputEcho << "It is a pleasure to serve you\n";
//	}
//}
//
//void Robot::Walk(WalkDirection direction)
//{
//	if (!m_turnedOn)
//	{
//		m_outputEcho << "The robot should be turned on first" << std::endl;
//		return;
//	}
//
//	m_direction = direction;
//	static const std::map<WalkDirection, std::string> directionToString = {
//		{ WalkDirection::East, "east" },
//		{ WalkDirection::South, "south" },
//		{ WalkDirection::West, "west" },
//		{ WalkDirection::North, "north" },
//	};
//	m_outputEcho << "Walking " << directionToString.at(direction) << std::endl;
//}
//
//void Robot::Stop()
//{
//	if (!m_turnedOn)
//	{
//		m_outputEcho << "The robot should be turned on first" << std::endl;
//		return;
//	}
//
//	if (m_direction)
//	{
//		m_direction.reset();
//		m_outputEcho << "Stopped\n";
//	}
//	else
//	{
//		m_outputEcho << "I am staying still\n";
//	}
//}
