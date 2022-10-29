#ifndef COMMAND_COMMANDS_COMPOUND_EDIT_H_
#define COMMAND_COMMANDS_COMPOUND_EDIT_H_

#include <deque>

#include "AbstractUndoableEdit.h"

class CompoundEdit : public AbstractUndoableEdit
{
public:
	template <typename StringT>
	CompoundEdit(StringT&& editName)
		: AbstractUndoableEdit(std::forward<StringT>(editName))
		, m_inCompose(true)
		, m_edits()
	{
	}

	bool AddEdit(const IUndoableEditSharedPtr& edit) final;
	bool EndCompose() noexcept;

protected:
	CompoundEdit() = default;

	bool DerivedExecute() override;
	bool DerivedUndo() override;
	bool DerivedRedo() override;

	std::deque<IUndoableEditSharedPtr> m_edits{};

private:
	bool m_inCompose = true;
};

#endif // !COMMAND_COMMANDS_COMPOUND_EDIT_H_
