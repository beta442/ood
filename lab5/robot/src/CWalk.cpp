#include "../include/CWalk.h"

using namespace robot;

CWalk::CWalk(Robot& robot, WalkDirection direction)
	: m_robot(robot)
	, m_direction(direction)
{
}

void CWalk::Execute()
{
	m_robot.Walk(m_direction);
}
