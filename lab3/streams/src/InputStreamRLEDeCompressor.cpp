#include "../include/InputStreamRLEDeCompressor.h"

#include <ios>

InputStreamRLEDeCompressor::InputStreamRLEDeCompressor(IInputDataStreamPtr&& inputStreamPtr)
	: InputStreamDecoratorBase(std::move(inputStreamPtr))
	, m_byteSequenceInfo()
{
}

uint8_t InputStreamRLEDeCompressor::ReadByte()
{
	if (m_byteSequenceInfo.size == 0 && m_wrappedStream->IsEOF() == false)
	{
		m_byteSequenceInfo.size = m_wrappedStream->ReadByte();
		if (m_wrappedStream->IsEOF() == false)
		{
			m_byteSequenceInfo.byte = m_wrappedStream->ReadByte();
		}
	}

	--m_byteSequenceInfo.size;

	return m_byteSequenceInfo.byte;
}

constexpr auto READ_BLOCK_FAILURE_NULLPTR_MSG = "Failed read block attempt. nullptr in _1 parameter is provided";

std::streamsize InputStreamRLEDeCompressor::ReadBlock(void* dstBuffer, std::streamsize size)
{
	if (dstBuffer == nullptr)
	{
		throw std::ios_base::failure(READ_BLOCK_FAILURE_NULLPTR_MSG);
	}

	auto buffer = static_cast<uint8_t*>(dstBuffer);

	for (std::streamsize i = 0; i < size; ++i, ++buffer)
	{
		*buffer = ReadByte();
	}

	return size;
}
