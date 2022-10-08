#include <iostream>

#include "../include/FileInputStream.h"
#include "../include/TryOpenFile.hpp"

FileInputStream::FileInputStream(const char* fileName)
	: InputStreamBase()
	, m_ifStream()
{
	TryOpenFile(m_ifStream, fileName);
}

FileInputStream::FileInputStream(const std::string& fileName)
	: m_ifStream()
{
	TryOpenFile(m_ifStream, fileName);
}

FileInputStream::~FileInputStream()
{
	m_ifStream.close();
}

bool FileInputStream::IsEOF() const
{
	return m_ifStream.eof();
}

constexpr auto READ_BYTE_FAILURE_MSG = "Failed byte read attempt";

uint8_t FileInputStream::DerivedReadByte()
{
	uint8_t byte;
	try
	{
		byte = static_cast<uint8_t>(m_ifStream.get());
	}
	catch (...)
	{
		throw std::ios_base::failure(READ_BYTE_FAILURE_MSG);
	}
	return byte;
}

constexpr auto READ_BLOCK_FAILURE_MSG = "Failed read block attempt";

std::streamsize FileInputStream::DerivedReadBlock(void* dstBuffer, std::streamsize size)
{
	try
	{
		m_ifStream.read(static_cast<char*>(dstBuffer), size);
	}
	catch (...)
	{
		throw std::ios_base::failure(READ_BLOCK_FAILURE_MSG);
	}
	return m_ifStream.gcount();
}