#ifndef COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_
#define COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_

#include <memory>

#include "IImage.h"
#include "IParagraph.h"

class DocumentItem
{
public:
	DocumentItem(const IElementSharedPtr& ptr);

	IImageSharedPtr GetImage();
	IImageSharedPtrConst GetImage() const;
	IParagraphSharedPtr GetParagraph();
	IParagraphSharedPtrConst GetParagraph() const;

private:
	IElementSharedPtr m_element;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_H_
