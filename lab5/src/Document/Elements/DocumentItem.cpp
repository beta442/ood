#include "../../../include/Document/Elements/DocumentItem.h"

DocumentItem::DocumentItem(const IElementSharedPtr& ptr)
	: m_element(ptr)
{
}

IImageSharedPtr DocumentItem::GetImage()
{
	if (auto ptr = std::dynamic_pointer_cast<IImage>(m_element);
		ptr)
	{
		return ptr;
	}
	return nullptr;
}

IImageSharedPtrConst DocumentItem::GetImage() const
{
	if (auto ptr = std::dynamic_pointer_cast<const IImage>(m_element);
		ptr)
	{
		return ptr;
	}
	return nullptr;
}

IParagraphSharedPtr DocumentItem::GetParagraph()
{
	if (auto ptr = std::dynamic_pointer_cast<IParagraph>(m_element);
		bool(ptr) == true)
	{
		return ptr;
	}
	return nullptr;
}

IParagraphSharedPtrConst DocumentItem::GetParagraph() const
{
	if (auto ptr = std::dynamic_pointer_cast<const IParagraph>(m_element);
		bool(ptr) == true)
	{
		return ptr;
	}
	return nullptr;
}
