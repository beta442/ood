#ifndef COMMAND_COMMANDS_UNDO_MANAGER_H_
#define COMMAND_COMMANDS_UNDO_MANAGER_H_

#include "CompoundEdit.h"

class UndoManager : private CompoundEdit
{
public:
	using CompoundEdit::Undo;
	using CompoundEdit::Redo;

	UndoManager() = default;

	bool CanUndo() const final;
	bool CanRedo() const final;

	void AddAndExecuteEdit(const IUndoableEditSharedPtr& edit);

private:
	bool DerivedExecute() final;
	bool DerivedUndo() final;
	bool DerivedRedo() final;

	size_t m_nextEditIndex{};
};

#endif // !COMMAND_COMMANDS_UNDO_MANAGER_H_
