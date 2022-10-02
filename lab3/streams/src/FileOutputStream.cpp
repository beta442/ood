#include "../include/FileOutputStream.h"
#include "../include/TryOpenFile.hpp"

FileOutputStream::FileOutputStream(const char* fileName)
{
	TryOpenFile(m_ofStream, fileName);
}

FileOutputStream::FileOutputStream(const std::string& fileName)
{
	TryOpenFile(m_ofStream, fileName);
}

FileOutputStream::~FileOutputStream()
{
	m_ofStream.close();
}

constexpr auto WRITE_BYTE_FAILURE_MSG = "Failed write byte attempt";

void FileOutputStream::WriteByte(uint8_t data)
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

void FileOutputStream::WriteBlock(const void* srcData, std::streamsize size)
{
	if (srcData == nullptr)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_NULLPTR_MSG);
	}

	try
	{
		m_ofStream.write(static_cast<const char*>(srcData), size);
		m_ofStream.flush();
	}
	catch (...)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_MSG);
	}
}
