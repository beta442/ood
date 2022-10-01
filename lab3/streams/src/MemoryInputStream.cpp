#include "../include/MemoryInputStream.h"

#include <algorithm>
#include <sstream>

MemoryInputStream::MemoryInputStream(const std::vector<uint8_t>& source)
	: m_iStringStream(source)
	, m_offset(0)
{
	auto sourceSize = source.size();
	m_iStringStream.resize(sourceSize + 1);
	m_iStringStream[sourceSize] = 0;
}

bool MemoryInputStream::IsEOF() const
{
	return m_offset == m_iStringStream.size();
}

constexpr auto READ_BYTE_FAILURE_MSG = "Failed byte read attempt";

uint8_t MemoryInputStream::ReadByte()
{
	if (IsEOF())
	{
		throw std::ios_base::failure(READ_BYTE_FAILURE_MSG);
	}

	return m_iStringStream[m_offset++];
}

constexpr auto READ_BLOCK_FAILURE_MSG = "Failed block read attempt";

std::streamsize MemoryInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	size = std::min(size, static_cast<std::streamsize>(m_iStringStream.size() - m_offset - 1));

	std::copy(m_iStringStream.begin(), m_iStringStream.begin() + size, static_cast<uint8_t*>(dstBuffer));
	m_offset += size + 1;

	return size;
}
