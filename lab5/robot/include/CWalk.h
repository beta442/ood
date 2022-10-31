#ifndef ROBOT_ROBOT_COMMANDS_CWALK_H_
#define ROBOT_ROBOT_COMMANDS_CWALK_H_

#include "ICommand.h"
#include "Robot.h"

namespace robot
{

class CWalk : public ICommand
{
public:
	CWalk(Robot& robot, WalkDirection direction);

	void Execute() final;

private:
	Robot& m_robot;
	WalkDirection m_direction;
};

}; // namespace robot

#endif // !ROBOT_ROBOT_COMMANDS_CWALK_H_
