#ifndef COMMAND_DOCUMENT_HTML_DOCUMENT_H_
#define COMMAND_DOCUMENT_HTML_DOCUMENT_H_

#include <string>

#include "../Commands/UndoManager.h"
#include "IDocument.h"

class HTMLDocument : public IDocument
{
public:
	HTMLDocument() = default;

	template <typename Title = std::string>
	HTMLDocument(Title&& string)
		: m_title(std::forward<Title>(string))
		, m_undoManager()
	{
	}

	const std::string& GetTitle() const final;
	void SetTitle(const std::string& title) final;

	bool CanUndo() const final;
	void Undo() final;
	bool CanRedo() const final;
	void Redo() final;

	void Save(const StdPath& path) const final;

private:
	std::string m_title{};

	UndoManager m_undoManager{};
};

#endif // !COMMAND_DOCUMENT_HTML_DOCUMENT_H_
