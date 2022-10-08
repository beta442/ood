#include "../include/InputStreamRLEDeCompressor.h"

InputStreamRLEDeCompressor::InputStreamRLEDeCompressor(IInputDataStreamPtr&& inputStreamPtr)
	: InputStreamDecoratorBase(std::move(inputStreamPtr))
	, m_byteSequenceInfo()
{
}

uint8_t InputStreamRLEDeCompressor::DerivedReadByte()
{
	if (m_byteSequenceInfo.size == 0)
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

std::streamsize InputStreamRLEDeCompressor::DerivedReadBlock(void* dstBuffer, std::streamsize size)
{
	auto buffer = static_cast<uint8_t*>(dstBuffer);

	for (std::streamsize i = 0; i < size; ++i, ++buffer)
	{
		*buffer = ReadByte();
	}

	return size;
}
