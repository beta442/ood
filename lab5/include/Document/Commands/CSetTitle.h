#ifndef COMMAND_DOCUMENT_COMMANDS_CSET_TITLE_H_
#define COMMAND_DOCUMENT_COMMANDS_CSET_TITLE_H_

#include <string>

#include "../../Commands/AbstractUndoableEdit.h"
#include "../../Document/IDocument.h"
#include "common.h"

class CSetTitle : public AbstractUndoableEdit
{
public:
	template <typename Title = std::string>
	CSetTitle(std::string& target, Title&& name)
		: AbstractUndoableEdit(document_commands::SET_TITLE_COMMAND_NAME)
		, m_target(target)
		, m_state(std::forward<Title>(name))
	{
	}

private:
	bool DerivedExecute() final;

	bool DerivedUndo() final;
	bool DerivedRedo() final;

	std::string& m_target;
	std::string m_state;
};

#endif // !COMMAND_DOCUMENT_COMMANDS_CSET_TITLE_H_
