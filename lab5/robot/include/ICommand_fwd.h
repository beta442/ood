#ifndef ROBOT_ICOMMAND_FWD_H_
#define ROBOT_ICOMMAND_FWD_H_

#include <memory>

namespace robot
{

class ICommand;

using ICommandRawPtr = ICommand*;
using ICommandPtr = std::unique_ptr<ICommand>;

}; // namespace robot

#endif // !ROBOT_ICOMMAND_FWD_H_
