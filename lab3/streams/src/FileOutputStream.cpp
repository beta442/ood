#include "../include/FileOutputStream.h"
#include "../include/TryOpenFile.hpp"

FileOutputStream::FileOutputStream(const char* fileName)
	: OutputStreamBase()
{
	TryOpenFile(m_ofStream, std::ios_base::binary, fileName);
}

FileOutputStream::FileOutputStream(const std::string& fileName)
	: OutputStreamBase()
{
	TryOpenFile(m_ofStream, std::ios_base::binary, fileName);
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

void FileOutputStream::DerivedWriteBlock(const void* srcData, std::streamsize size)
{
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
