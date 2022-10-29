#ifndef COMMAND_EDITOR_EDITOR_H_
#define COMMAND_EDITOR_EDITOR_H_

#include <iostream>

#include "../Document/HTMLDocument.h"
#include "../Menu/Menu.h"

class Editor
{
public:
	Editor(IDocumentPtr&& document, std::istream& menuInput, std::ostream& menuOutput);

	void Start();

private:
	void Redo();
	void Undo();

	void DeleteItem(std::istream& is);
	void InsertParagparh(std::istream& is);
	void InsertImage(std::istream& is);
	void ListDocument();
	void ReplaceText(std::istream& is);
	void Save(std::istream& is);
	void SetTitle(std::istream& is);

	IDocumentPtr m_document;
	Menu m_menu;

	std::ostream& m_outputEcho;
};

#endif // !COMMAND_EDITOR_EDITOR_H_
