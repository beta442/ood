#include <fstream>

#include "../../include/Document/HTMLDocument.h"

#include "../../include/Document/Commands/CSetTitle.h"

const std::string& HTMLDocument::GetTitle() const
{
	return m_title;
}

void HTMLDocument::SetTitle(const std::string& title)
{
	m_undoManager.AddAndExecuteEdit(std::make_shared<CSetTitle>(m_title, title));
}

bool HTMLDocument::CanUndo() const
{
	return m_undoManager.CanUndo();
}

void HTMLDocument::Undo()
{
	if (!CanUndo())
	{
		return;
	}

	m_undoManager.Undo();
}

bool HTMLDocument::CanRedo() const
{
	return m_undoManager.CanRedo();
}

void HTMLDocument::Redo()
{
	if (!CanRedo())
	{
		return;
	}

	m_undoManager.Redo();
}

constexpr auto HTML_EXTENSION = ".html";

std::ofstream CreateHTMLHandler(const StdPath& path)
{
	return std::ofstream{ (path.extension() == HTML_EXTENSION)
			? path.generic_string()
			: path.generic_string() + HTML_EXTENSION };
}

void HTMLDocument::Save(const StdPath& path) const
{
	std::ofstream fHandler = CreateHTMLHandler(path);
}
