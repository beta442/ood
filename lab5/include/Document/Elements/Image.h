#ifndef COMMAND_DOCUMENT_ELEMENTS_IMAGE_H_
#define COMMAND_DOCUMENT_ELEMENTS_IMAGE_H_

#include "../common.h"
#include "IImage.h"

class Image : public IImage
{
public:
	Image(const StdPath& path, size_t width, size_t height);

	const StdPath& GetPath() const final;
	size_t GetWidth() const final;
	size_t GetHeight() const final;
	void Resize(size_t width, size_t height) final;

private:
	StdPath m_path{};
	size_t m_width{}, m_height{};
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_IMAGE_H_
