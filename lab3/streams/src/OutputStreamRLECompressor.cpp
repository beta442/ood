#include <ios>

#include "../include/OutputStreamRLECompressor.h"

OutputStreamRLECompressor::OutputStreamRLECompressor(IOutputDataStreamPtr&& outputStreamPtr)
	: OutputStreamDecoratorBase(std::move(outputStreamPtr))
	, m_byteSequenceInfo()
{
}

OutputStreamRLECompressor::~OutputStreamRLECompressor()
{
	Flush();
}

void OutputStreamRLECompressor::WriteByte(uint8_t data)
{
	if (m_byteSequenceInfo.size == 0)
	{
		m_byteSequenceInfo = { 1, data };

		return;
	}

	if (m_byteSequenceInfo.byte == data && m_byteSequenceInfo.size < std::numeric_limits<uint8_t>::max())
	{
		++m_byteSequenceInfo.size;
		return;
	}

	Flush();
	m_byteSequenceInfo = { 1, data };
}

constexpr auto WRITE_BLOCK_FAILURE_NULLPTR_MSG = "Failed write block attempt. nullptr in _1 parameter is provided";

void OutputStreamRLECompressor::WriteBlock(const void* srcData, std::streamsize size)
{
	if (srcData == nullptr)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_NULLPTR_MSG);
	}

	auto buffer = static_cast<const uint8_t*>(srcData);

	for (std::streamsize index = 0; index < size; ++index)
	{
		WriteByte(*(buffer++));
	}
}

void OutputStreamRLECompressor::Flush()
{
	m_wrappedStream->WriteByte(m_byteSequenceInfo.size);
	m_wrappedStream->WriteByte(m_byteSequenceInfo.byte);
	m_byteSequenceInfo = { 0, 0 };
}