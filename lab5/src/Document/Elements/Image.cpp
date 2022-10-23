#include "../../../include/Document/Elements/Image.h"

Image::Image(const StdPath& path, size_t width, size_t height)
	: m_path(path)
	, m_width(width)
	, m_height(height)
{
}

const StdPath& Image::GetPath() const
{
	return m_path;
}

size_t Image::GetWidth() const
{
	return m_width;
}

size_t Image::GetHeight() const
{
	return m_height;
}

void Image::Resize(size_t width, size_t height)
{
	m_width = width;
	m_height = height;
}
