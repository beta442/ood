#ifndef COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_
#define COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_

#include <memory>

#include "ConstDocumentItem.h"
#include "IImage.h"
#include "IParagraph.h"

class DocumentItem : public ConstDocumentItem
{
public:
	// Возвращает указатель на изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<IImage> GetImage();
	// Возвращает указатель на параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<IParagraph> GetParagraph();
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_
