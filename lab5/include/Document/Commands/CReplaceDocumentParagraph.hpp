#ifndef COMMAND_DOCUMENT_COMMANDS_CREPLACE_DOCUMENT_PARAGRAPH_HPP_
#define COMMAND_DOCUMENT_COMMANDS_CREPLACE_DOCUMENT_PARAGRAPH_HPP_

#include <memory>
#include <stdexcept>

#include "../../Commands/CompoundEdit.h"
#include "../Elements/DocumentItem.h"
#include "../Elements/Paragraph.h"
#include "CDeleteDocumentItem.hpp"
#include "CInsertDocumentItem.hpp"
#include "common.h"

template <typename DocumentInnerContainerT>
class CReplaceDocumentItem : public CompoundEdit
{
public:
	CReplaceDocumentItem(DocumentInnerContainerT& target,
		const DocumentItem& oldDocItem,
		const DocumentItem& newDocItem,
		size_t index)
		: CompoundEdit(document_commands::REPLACE_DOCUMENT_ITEM_COMMAND_NAME)
		, m_target(target)
		, m_index(index)
	{
		if (index >= target.size())
		{
			throw std::out_of_range("Failed to replace item in Document. Given index is out of range");
		}

		auto firstC = std::make_shared<CDeleteDocumentItem<DocumentInnerContainerT>>(target,
			oldDocItem,
			index);
		auto secondC = std::make_shared<CInsertDocumentItem<DocumentInnerContainerT>>(target,
			newDocItem,
			index);
		m_edits.emplace_back(std::move(firstC));
		m_edits.emplace_back(std::move(secondC));
	}

private:
	DocumentInnerContainerT& m_target;

	size_t m_index;
};

#endif // !COMMAND_DOCUMENT_COMMANDS_CREPLACE_DOCUMENT_PARAGRAPH_HPP_
