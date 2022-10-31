#include "../include/CTurnOn.h"

using namespace robot;

CTurnOn::CTurnOn(Robot& robot)
	: m_robot(robot)
{
}

void CTurnOn::Execute()
{
	m_robot.TurnOn();
}
