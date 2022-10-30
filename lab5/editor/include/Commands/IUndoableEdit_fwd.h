#ifndef COMMAND_COMMANDS_IUNDOABLE_EDIT_FWD_H_
#define COMMAND_COMMANDS_IUNDOABLE_EDIT_FWD_H_

#include <memory>

class IUndoableEdit;

using IUndoableEditPtr = std::unique_ptr<IUndoableEdit>;
using IUndoableEditSharedPtr = std::shared_ptr<IUndoableEdit>;

#endif // !COMMAND_COMMANDS_IUNDOABLE_EDIT_FWD_H_
