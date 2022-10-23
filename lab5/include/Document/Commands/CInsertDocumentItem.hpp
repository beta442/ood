#ifndef COMMAND_DOCUMENT_COMMANDS_INSERT_DOCUMENT_ITEM_HPP_
#define COMMAND_DOCUMENT_COMMANDS_INSERT_DOCUMENT_ITEM_HPP_

#include <string>

#include "../../Commands/AbstractUndoableEdit.h"
#include "../Elements/DocumentItem.h"
#include "common.h"

template <typename DocumentInnerContainerT>
class CInsertDocumentItem : public AbstractUndoableEdit
{
public:
	CInsertDocumentItem(DocumentInnerContainerT& target, const DocumentItem& docItem, size_t index)
		: AbstractUndoableEdit(document_commands::INSERT_DOCUMENT_ITEM_COMMAND_NAME)
		, m_target(target)
		, m_state(docItem)
		, m_index(index)
	{
	}

private:
	bool DerivedExecute() final
	{
		if (m_index > m_target.size())
		{
			throw std::out_of_range("Failed to insert a paragraph into Document. Given index is out of range");
		}

		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.emplace(it, m_state);

		return true;
	}

	bool DerivedUndo() final
	{
		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.erase(it);

		return true;
	}

	bool DerivedRedo() final
	{
		return DerivedExecute();
	}

	DocumentInnerContainerT& m_target;

	size_t m_index{};
	DocumentItem m_state;
};

#endif // !COMMAND_DOCUMENT_COMMANDS_INSERT_PARAGRAPH_HPP_
