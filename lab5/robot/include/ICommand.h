#ifndef ROBOT_ICOMMAND_H_
#define ROBOT_ICOMMAND_H_

#include "ICommand_fwd.h"

namespace robot
{

class ICommand
{
public:
	virtual void Execute() = 0;

	virtual ~ICommand() = default;
};

}; // namespace robot

#endif // !ROBOT_ICOMMAND_H_
