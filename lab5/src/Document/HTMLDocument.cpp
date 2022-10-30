#include "../../include/pch.h"

#include "../../include/Document/Commands/CDeleteDocumentItem.hpp"
#include "../../include/Document/Commands/CInsertDocumentItem.hpp"
#include "../../include/Document/Commands/CReplaceDocumentItem.hpp"
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

std::tuple<std::ofstream, StdPath> CreateHTMLHandler(const StdPath& path, const std::string& fileName)
{
	StdPath correctPath = path;
	correctPath /= fileName;
	correctPath = correctPath.replace_extension(HTML_EXTENSION);

	return std::make_tuple(std::ofstream{ correctPath.generic_string() }, correctPath);
}


std::string MakeImageTag(const IImageSharedPtrConst& image)
{
	auto imageSrc = StdPath(".");
	imageSrc /= IMAGES_SAVE_DIR_NAME;
	imageSrc /= image->GetName();
	imageSrc.replace_extension(image->GetPath().extension());

	auto imageWidth = std::to_string(image->GetWidth());
	auto imageHeight = std::to_string(image->GetHeight());

	return std::string("<img src=\"") + imageSrc.generic_string() + "\" width=\"" + imageWidth + "\" height=\"" + imageHeight + "\"/>";
}

constexpr auto INDENT_SIZE = 2;
constexpr auto DOCTYPE_STR = "<!DOCTYPE html>\n";

void FormHtmlDocument(const std::string& title, const HTMLDocument::Container& items, std::ostream& output, const StdPath& savePath)
{
	output << DOCTYPE_STR;

	size_t indentIndex{};
	output << "<html lang=\"en\">\n"
		   << MakeSpaceIndentString(' ', INDENT_SIZE, ++indentIndex) + "<head>\n"
		   << MakeSpaceIndentString(' ', INDENT_SIZE, ++indentIndex) + "<title>" + title + "</title>\n"
		   << MakeSpaceIndentString(' ', INDENT_SIZE, --indentIndex) + "</head>\n"
		   << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex) + "<body>\n";

	StdPath imagesSavePath = std::filesystem::current_path(), relativeImagesPath = savePath;
	relativeImagesPath /= IMAGES_SAVE_DIR_NAME;
	imagesSavePath /= relativeImagesPath;

	if (!std::filesystem::exists(imagesSavePath))
	{
		std::filesystem::create_directory(imagesSavePath);
	}

	++indentIndex;
	for (const auto& item : items)
	{
		auto imagePtr = item.GetImage();
		auto paragraphPtr = item.GetParagraph();

		if (imagePtr != nullptr)
		{
			output << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex);
			try
			{
				imagePtr->Save(imagesSavePath);
				output << MakeImageTag(imagePtr);
			}
			catch (...)
			{
				output << "<!--Failed to save '" + imagePtr->GetName() + "' image-->";
			}
		}

		if (paragraphPtr != nullptr)
		{
			output << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex) + "<p>" + paragraphPtr->GetText() + "</p>";
		}
		output << '\n';
	}
	--indentIndex;

	output << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex) + "</body>\n"
		   << "</html>" << std::endl;
}

void HTMLDocument::Save(const StdPath& path) const
{
	if (!std::filesystem::is_directory(path))
	{
		std::filesystem::create_directory(path);
	}

	auto [fHandler, savePath] = CreateHTMLHandler(path, GetTitle());

	FormHtmlDocument(m_title, m_items, fHandler, savePath.parent_path());
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
