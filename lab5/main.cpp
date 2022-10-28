#include "include/pch.h"

#include "include/Document/HTMLDocument.h"
#include "include/Editor/Editor.h"

int main(int, char**)
{
	auto doc = std::make_unique<HTMLDocument>();
	Editor editor{ std::move(doc), std::cin, std::cout };
	editor.Start();

	return 0;
}
