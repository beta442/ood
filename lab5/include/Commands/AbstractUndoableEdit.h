#ifndef COMMAND_COMMANDS_ABSTRACT_UNDOABLE_EDIT_H_
#define COMMAND_COMMANDS_ABSTRACT_UNDOABLE_EDIT_H_

#include <string>

#include "IUndoableEdit.h"

class AbstractUndoableEdit : public IUndoableEdit
{
public:
	void Execute() final;

	bool CanUndo() const noexcept override;
	bool CanRedo() const noexcept override;

	void Undo() override;
	void Redo() override;

	bool AddEdit(const IUndoableEditSharedPtr& edit) override;
	bool ReplaceEdit(const IUndoableEditSharedPtr& edit) override;

	const std::string_view& GetName() const noexcept final;

	void operator()() final;

protected:
	AbstractUndoableEdit() = default;

	template <typename EditName = std::string>
	AbstractUndoableEdit(EditName&& editName)
		: m_name(std::forward<EditName>(editName))
		, m_wasExecuted(false)
	{
	}
	~AbstractUndoableEdit();

	virtual bool DerivedExecute() = 0;

	virtual bool DerivedUndo() = 0;
	virtual bool DerivedRedo() = 0;

	void Destroy() override;

private:
	bool m_wasExecuted = false;
	std::string m_name{};
};

#endif // !COMMAND_COMMANDS_ABSTRACT_UNDOABLE_EDIT_H_
