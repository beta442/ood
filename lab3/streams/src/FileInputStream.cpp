#include "../include/FileInputStream.h"

constexpr auto DEFAULT_STREAM_OPEN_MODE = std::ios_base::in;

template <typename FileNameT>
void FileExists(std::ifstream& stream, FileNameT&& fileName)
{
	stream.open(fileName, DEFAULT_STREAM_OPEN_MODE);
	if (!stream.is_open())
	{
		throw std::ios_base::failure("Failed to open '" + std::string(std::forward<FileNameT>(fileName)) + "' file");
	}
}

FileInputStream::FileInputStream(const char* fileName)
	: m_ifStream()
{
	FileExists(m_ifStream, fileName);
}

FileInputStream::FileInputStream(const std::string& fileName)
	: m_ifStream()
{
	FileExists(m_ifStream, fileName);
}

FileInputStream::~FileInputStream()
{
	m_ifStream.close();
}

bool FileInputStream::IsEOF() const
{
	return m_ifStream.rdstate() & std::ios_base::eofbit;
}

constexpr auto READ_BYTE_FAILURE_MSG = "Failed byte read attempt";

uint8_t FileInputStream::ReadByte()
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
constexpr auto READ_BLOCK_FAILURE_NULLPTR_MSG = "Failed read block attempt. Got nullptr in _1 parameter";

std::streamsize FileInputStream::ReadBlock(void* dstBuffer, std::streamsize size)
{
	if (dstBuffer == nullptr)
	{
		throw std::ios_base::failure(READ_BLOCK_FAILURE_NULLPTR_MSG);
	}

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