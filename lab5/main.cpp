#include "include/pch.h"

#include "include/Document/HTMLDocument.h"
#include "include/Editor/Editor.h"

//q:
// 1. shared_ptr inside undoableEdit,
// 2. begin() end() inside IDocument
// 3. reference vs. weak_ptr inside commands
// 4. protected + private inheritance and destrcutor visibility
// 5. what edits can be compund in such html editing?
// 6. see AbstractUndoableEdit.h /w .cpp
// 7. getters `const R&` can be marked as noexcept?
// 8. getters with built-in `R` throw?

int main(int, char**)
{
	auto doc = std::make_unique<HTMLDocument>();
	Editor editor{ std::move(doc), std::cin, std::cout };
	editor.Start();

	return 0;
}
