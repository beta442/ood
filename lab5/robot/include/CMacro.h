#ifndef ROBOT_COMMANDS_CMACRO_H_
#define ROBOT_COMMANDS_CMACRO_H_

#include <vector>

#include "ICommand.h"

namespace robot
{

class CMacro : public ICommand
{
public:
	void AddCommand(ICommandPtr&& cmd);
	void Execute() final;

private:
	std::vector<ICommandPtr> m_commands;
};

}; // namespace robot

#endif // !ROBOT_COMMANDS_CMACRO_H_
