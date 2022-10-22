#ifndef COMMAND_COMMANDS_IUNDOABLE_EDIT_H_
#define COMMAND_COMMANDS_IUNDOABLE_EDIT_H_

#include <string>

#include "IUndoableEdit_fwd.h"

class IUndoableEdit
{
public:
	virtual void Execute() = 0;

	virtual bool CanUndo() const noexcept = 0;
	virtual bool CanRedo() const noexcept = 0;

	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual void Destroy() = 0;

	virtual bool AddEdit(const IUndoableEditSharedPtr& edit) = 0;
	virtual bool ReplaceEdit(const IUndoableEditSharedPtr& edit) = 0;

	virtual const std::string_view& GetName() const noexcept = 0;

	virtual void operator()() = 0;

	virtual ~IUndoableEdit() = default;
};

#endif // !COMMAND_COMMANDS_IUNDOABLE_EDIT_H_
