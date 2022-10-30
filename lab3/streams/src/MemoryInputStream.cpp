#include <sstream>

#include "../include/MemoryInputStream.h"

MemoryInputStream::MemoryInputStream(const std::vector<uint8_t>& source)
	: InputStreamBase()
	, m_iMemoryStream(source)
	, m_offset(0)
{
	auto sourceSize = source.size();
	m_iMemoryStream.resize(sourceSize + 1);
	m_iMemoryStream[sourceSize] = 0;
}

bool MemoryInputStream::IsEOF() const
{
	return m_offset == m_iMemoryStream.size();
}

uint8_t MemoryInputStream::DerivedReadByte()
{
	return m_iMemoryStream[m_offset++];
}

std::streamsize MemoryInputStream::DerivedReadBlock(void* dstBuffer, std::streamsize size)
{
	size = std::min(size, static_cast<std::streamsize>(m_iMemoryStream.size() - m_offset - 1));

	std::copy(m_iMemoryStream.begin(), m_iMemoryStream.begin() + size, static_cast<unsigned char*>(dstBuffer));
	m_offset += size + 1;

	return size;
}
