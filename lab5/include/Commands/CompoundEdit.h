#ifndef COMMAND_COMMANDS_COMPOUND_EDIT_H_
#define COMMAND_COMMANDS_COMPOUND_EDIT_H_

#include <string>
#include <deque>

#include "AbstractUndoableEdit.h"

class CompoundEdit : public AbstractUndoableEdit
{
public:
	template <typename EditName = std::string>
	CompoundEdit(EditName&& editName)
		: AbstractUndoableEdit(std::forward<EditName>(editName))
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
