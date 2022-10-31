#include "../include/CTurnOff.h"

using namespace robot;

CTurnOff::CTurnOff(Robot& robot)
	: m_robot(robot)
{
}

void CTurnOff::Execute()
{
	m_robot.TurnOff();
}
