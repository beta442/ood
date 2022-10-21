#ifndef COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_
#define COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_

#include <memory>

#include "IImage.h"
#include "IParagraph.h"

class ConstDocumentItem
{
public:
	// ���������� ��������� �� ����������� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage() const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~ConstDocumentItem() = default;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_CONST_DOCUMENT_ITEM_H_
