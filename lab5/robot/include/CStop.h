#ifndef ROBOT_ROBOT_COMMANDS_CSTOP_H_
#define ROBOT_ROBOT_COMMANDS_CSTOP_H_

#include "ICommand.h"
#include "Robot.h"

namespace robot
{

class CStop : public ICommand
{
public:
	CStop(Robot& robot);

	void Execute() final;

private:
	Robot& m_robot;
};

}; // namespace robot

#endif // !ROBOT_ROBOT_COMMANDS_CSTOP_H_
