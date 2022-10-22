#include "include/pch.h"

#include "include/Document/HTMLDocument.h"
#include "include/Document/Commands/CSetTitle.h"

template <typename Undoable>
void UndoRedoEditStatus(Undoable&& undoable, std::ostream& os)
{
	os << "Can Undo: " << undoable->CanUndo() << " Can Redo: " << undoable->CanRedo() << '\n';
}

int main(int, char**)
{
	auto doc = std::make_shared<HTMLDocument>("oldName");
	UndoRedoEditStatus(doc, std::cout);
	std::cout << doc->GetTitle() << '\n';
	doc->SetTitle("haha");
	UndoRedoEditStatus(doc, std::cout);
	std::cout << doc->GetTitle() << '\n';
	UndoRedoEditStatus(doc, std::cout);
	doc->Undo();
	std::cout << doc->GetTitle() << '\n';
 	UndoRedoEditStatus(doc, std::cout);
	doc->Undo();
	std::cout << doc->GetTitle() << '\n';
	UndoRedoEditStatus(doc, std::cout);
	doc->Redo();
	std::cout << doc->GetTitle() << '\n';
	UndoRedoEditStatus(doc, std::cout);
	doc->Redo();
	std::cout << doc->GetTitle() << '\n';
	UndoRedoEditStatus(doc, std::cout);

	return 0;
}
