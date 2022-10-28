#ifndef COMMAND_DOCUMENT_COMMANDS_CDELETE_DOCUMENT_ITEM_HPP_
#define COMMAND_DOCUMENT_COMMANDS_CDELETE_DOCUMENT_ITEM_HPP_

#include "../../Commands/AbstractUndoableEdit.h"
#include "../Elements/DocumentItem.h"
#include "common.h"

template <typename DocumentInnerContainerT>
class CDeleteDocumentItem : public AbstractUndoableEdit
{
public:
	CDeleteDocumentItem(DocumentInnerContainerT& target, const DocumentItem& item, size_t index)
		: AbstractUndoableEdit(document_commands::DELETE_DOCUMENT_ITEM_COMMAND_NAME)
		, m_target(target)
		, m_index(index)
		, m_state(item)
	{
	}

private:
	bool DerivedExecute() final
	{
		if (m_index > m_target.size())
		{
			throw std::out_of_range("Failed to delete an item from Document. Given index is out of range");
		}

		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.erase(it);

		return true;
	}

	bool DerivedUndo() final
	{
		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.emplace(it, m_state);

		return true;
	}

	bool DerivedRedo() final
	{
		return DerivedExecute();
	}

	DocumentInnerContainerT& m_target;

	size_t m_index;
	DocumentItem m_state;
};

#endif // !COMMAND_DOCUMENT_COMMANDS_CDELETE_DOCUMENT_ITEM_HPP_
