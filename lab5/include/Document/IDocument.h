#ifndef COMMAND_DOCUMENT_H_
#define COMMAND_DOCUMENT_H_

#include <iterator>
#include <memory>
#include <optional>
#include <string>

#include "common.h"

#include "Elements/DocumentItem.h"
#include "Elements/IImage.h"
#include "Elements/IParagraph.h"
#include "IDocument_fwd.h"

class IDocument
{
public:
	using Path = StdPath;

	virtual IParagraphSharedPtr InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt)
		= 0;

	// ��� ������� ����������� ������ ������������ � ���������� images
	// ��� ������������� ��������������� ������
	virtual IImageSharedPtr InsertImage(const Path& path, size_t width, size_t height,
		std::optional<size_t> position = std::nullopt)
		= 0;

	virtual size_t GetItemsCount() const = 0;

	virtual const DocumentItem& GetItem(size_t index) const = 0;

	virtual void DeleteItem(size_t index) = 0;

	virtual const std::string& GetTitle() const = 0;
	virtual void SetTitle(const std::string& title) = 0;

	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;

	// ��������� �������� � ������� html. ����������� ����������� � ���������� images.
	// ���� � ������������ ����������� ������������ ���� � ������������ HTML �����
	virtual void Save(const Path& path) const = 0;

	virtual ~IDocument() = default;
};

namespace document_item_types
{

constexpr auto PARAGRAPH_TYPE_STR = "Paragraph";
constexpr auto IMAGE_TYPE_STR = "Image";

}; // namespace html_document_item_types

#endif
