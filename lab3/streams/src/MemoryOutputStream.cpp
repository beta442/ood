#include "../include/MemoryOutputStream.h"

#include <sstream>

MemoryOutputStream::MemoryOutputStream()
	: m_oMemoryStream()
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
constexpr auto WRITE_BLOCK_FAILURE_NULLPTR_MSG = "Failed write block attempt. nullptr in _1 parameter is provided";

void MemoryOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	if (srcData == nullptr)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_NULLPTR_MSG);
	}

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
