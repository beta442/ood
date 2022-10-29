#include "../../include/pch.h"

#include "../../include/Document/Commands/CDeleteDocumentItem.hpp"
#include "../../include/Document/Commands/CInsertDocumentItem.hpp"
#include "../../include/Document/Commands/CReplaceDocumentParagraph.hpp"
#include "../../include/Document/Commands/CSetTitle.h"
#include "../../include/Document/Elements/Image.h"
#include "../../include/Document/Elements/Paragraph.h"
#include "../../include/Document/HTMLDocument.h"

IParagraphSharedPtr HTMLDocument::InsertParagraph(const std::string& text,
	std::optional<size_t> position)
{
	auto newParagraph = std::make_shared<Paragraph>(text);
	auto newDocumentItem = DocumentItem{ newParagraph };
	m_undoManager.AddAndExecuteEdit(
		std::make_shared<CInsertDocumentItem<Container>>(m_items,
			newDocumentItem,
			(position.has_value()) ? *position : GetItemsCount()));

	return newParagraph;
}

IParagraphSharedPtr HTMLDocument::ReplaceParagraph(const std::string& newText,
	std::optional<size_t> position)
{
	auto index = (position.has_value()) ? *position : m_items.size() - 1;
	if (index >= m_items.size())
	{
		throw std::out_of_range("Failed to replace paragraph's text in Document. Given index is out of range");
	}

	auto oldItem = m_items[index];
	if (oldItem.GetParagraph() == nullptr)
	{
		throw std::invalid_argument("Document doesn't contain paragraph at given index.");
	}

	auto newParagraph = std::make_shared<Paragraph>(newText);
	auto newDocumentItem = DocumentItem{ newParagraph };
	m_undoManager.AddAndExecuteEdit(
		std::make_shared<CReplaceDocumentItem<Container>>(m_items,
			oldItem,
			newDocumentItem,
			(position.has_value()) ? *position : GetItemsCount()));

	return newParagraph;
}

IImageSharedPtr HTMLDocument::InsertImage(const Path& path, size_t width, size_t height,
	std::optional<size_t> position)
{
	auto newImage = std::make_shared<Image>(path, width, height);
	auto newDocumentItem = DocumentItem{ newImage };
	m_undoManager.AddAndExecuteEdit(
		std::make_shared<CInsertDocumentItem<Container>>(m_items,
			newDocumentItem,
			(position.has_value()) ? *position : GetItemsCount()));

	return newImage;
}

IImageSharedPtr HTMLDocument::ResizeImage(size_t width, size_t height,
	std::optional<size_t> position)
{
	auto index = (position.has_value()) ? *position : m_items.size() - 1;
	if (index >= m_items.size())
	{
		throw std::out_of_range("Failed to replace image in Document. Given index is out of range");
	}

	auto oldItem = m_items[index];
	auto oldImage = m_items[index].GetImage();
	if (oldImage == nullptr)
	{
		throw std::invalid_argument("Document doesn't contain paragraph at given index.");
	}

	auto newImage = std::make_shared<Image>(oldImage->GetPath(), width, height);
	auto newDocumentItem = DocumentItem{ newImage };
	m_undoManager.AddAndExecuteEdit(
		std::make_shared<CReplaceDocumentItem<Container>>(m_items,
			oldItem,
			newDocumentItem,
			(position.has_value()) ? *position : GetItemsCount()));

	return newImage;
}

size_t HTMLDocument::GetItemsCount() const
{
	return m_items.size();
}

const DocumentItem& HTMLDocument::GetItem(size_t index) const
{
	if (index >= GetItemsCount())
	{
		throw std::out_of_range("Failed to get item from HTMLDocument. Given index is out of range");
	}

	return m_items[index];
}

void HTMLDocument::DeleteItem(size_t index)
{
	if (index >= m_items.size())
	{
		throw std::out_of_range("Failed to delete item in HTMLDocument. Given index is out of range");
	}

	m_undoManager.AddAndExecuteEdit(std::make_shared<CDeleteDocumentItem<Container>>(m_items,
		GetItem(index),
		index));
}

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
	m_undoManager.Undo();
}

bool HTMLDocument::CanRedo() const
{
	return m_undoManager.CanRedo();
}

void HTMLDocument::Redo()
{
	m_undoManager.Redo();
}

constexpr auto HTML_EXTENSION = ".html";

// std::ofstream CreateHTMLHandler(const StdPath& path)
//{
//	return std::ofstream{ (path.extension() == HTML_EXTENSION)
//			? path.generic_string()
//			: path.generic_string() + HTML_EXTENSION };
// }

constexpr auto IMAGES_DIRECTORY = "images";

void HTMLDocument::Save(const StdPath& path) const
{
	const auto directory = std::filesystem::path(path).parent_path() / IMAGES_DIRECTORY;

	if (!std::filesystem::is_directory(directory))
	{
		std::filesystem::create_directory(directory);
	}

	// std::ofstream fHandler = CreateHTMLHandler(path);
}

using Iterator = HTMLDocument::Iterator;
using ConstIterator = HTMLDocument::ConstIterator;

Iterator HTMLDocument::begin()
{
	return std::make_unique<IteratorWrapper<DocumentItem, Container::iterator>>(m_items.begin(), m_items.end());
}

ConstIterator HTMLDocument::begin() const
{
	return std::make_unique<IteratorWrapper<const DocumentItem, Container::const_iterator>>(m_items.begin(), m_items.end());
}
