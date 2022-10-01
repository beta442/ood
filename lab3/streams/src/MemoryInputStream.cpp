#include "../include/MemoryInputStream.h"

#include <sstream>

MemoryInputStream::MemoryInputStream(const std::vector<uint8_t>& source)
	: m_iMemoryStream(source)
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

constexpr auto READ_BYTE_FAILURE_MSG = "Failed byte read attempt";

uint8_t MemoryInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw std::ios_base::failure(READ_BYTE_FAILURE_MSG);
	}

	return m_iMemoryStream[m_offset++];
}

std::streamsize MemoryInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	size = std::min(size, static_cast<std::streamsize>(m_iMemoryStream.size() - m_offset - 1));

	std::copy(m_iMemoryStream.begin(), m_iMemoryStream.begin() + size, static_cast<uint8_t*>(dstBuffer));
	m_offset += size + 1;

	return size;
}
