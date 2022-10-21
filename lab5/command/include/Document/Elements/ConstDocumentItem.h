#ifndef COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_
#define COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_

#include <memory>

#include "IImage.h"
#include "IParagraph.h"

class ConstDocumentItem
{
public:
	// Возвращает указатель на константное изображение, либо nullptr,
	// если элемент не является изображением
	std::shared_ptr<const IImage> GetImage() const;
	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~ConstDocumentItem() = default;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_
