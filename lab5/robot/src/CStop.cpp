#include "../include/CStop.h"

using namespace robot;

CStop::CStop(Robot& robot)
	: m_robot(robot)
{
}

void CStop::Execute()
{
	m_robot.Stop();
}
