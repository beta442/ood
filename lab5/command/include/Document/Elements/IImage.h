#ifndef COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_
#define COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_

class IImage
{
public:
	// ���������� ���� ������������ �������� ���������
	virtual Path GetPath() const = 0;

	// ������ ����������� � ��������
	virtual int GetWidth() const = 0;
	// ������ ����������� � ��������
	virtual int GetHeight() const = 0;

	// �������� ������ �����������
	virtual void Resize(int width, int height) = 0;

	virtual ~IImage() = default;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_
