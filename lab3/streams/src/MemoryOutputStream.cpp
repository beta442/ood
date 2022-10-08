#include "../include/MemoryOutputStream.h"

#include <sstream>

MemoryOutputStream::MemoryOutputStream()
	: OutputStreamBase()
	, m_oMemoryStream()
{
}

constexpr auto WRITE_BYTE_FAILURE_MSG = "Failed write byte attempt";

void MemoryOutputStream::WriteByte(uint8_t data)
{
	try
	{
		WriteBlock(&data, 1);
	}
	catch (...)
	{
		throw std::ios_base::failure(WRITE_BYTE_FAILURE_MSG);
	}
}

constexpr auto WRITE_BLOCK_FAILURE_MSG = "Failed write block attempt";

void MemoryOutputStream::DerivedWriteBlock(const void* srcData, std::streamsize size)
{
	try
	{
		m_oMemoryStream.reserve(m_oMemoryStream.size() + size);

		std::copy(static_cast<const uint8_t*>(srcData), static_cast<const uint8_t*>(srcData) + size, std::back_inserter(m_oMemoryStream));
	}
	catch (...)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_MSG);
	}
}
