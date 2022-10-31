#ifndef ROBOT_ROBOT_COMMANDS_CTURN_ON_H_
#define ROBOT_ROBOT_COMMANDS_CTURN_ON_H_

#include "ICommand.h"
#include "Robot.h"

namespace robot
{

class CTurnOn : public ICommand
{
public:
	CTurnOn(Robot& robot);

	void Execute() final;

private:
	Robot& m_robot;
};

}; // namespace robot

#endif // !ROBOT_ROBOT_COMMANDS_CTURN_ON_H_
