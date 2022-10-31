#ifndef ROBOT_ROBOT_COMMANDS_CTURN_OFF_H_
#define ROBOT_ROBOT_COMMANDS_CTURN_OFF_H_

#include "ICommand.h"
#include "Robot.h"

namespace robot
{

class CTurnOff : public ICommand
{
public:
	CTurnOff(Robot& robot);

	void Execute() final;

private:
	Robot& m_robot;
};

}; // namespace robot

#endif // !ROBOT_ROBOT_COMMANDS_CTURN_OFF_H_
