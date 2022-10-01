#include <algorithm>

#include "../include/CryptTableGenerator.h"
#include "../include/InputStreamDeCrypter.h"

InputStreamDeCrypter::InputStreamDeCrypter(IInputDataStreamPtr&& inputStreamPtr, unsigned char key)
	: InputStreamDecoratorBase(std::move(inputStreamPtr))
	, m_deCryptTable(std::move(GenerateTable(key)))
	, m_key(key)
{
}

uint8_t InputStreamDeCrypter::ReadByte()
{
	auto byte = m_wrappee->ReadByte();

	return m_deCryptTable[byte];
}

std::streamsize InputStreamDeCrypter::ReadBlock(void* dstBuffer, std::streamsize size)
{
	auto res = m_wrappee->ReadBlock(dstBuffer, size);

	std::for_each(static_cast<uint8_t*>(dstBuffer), static_cast<uint8_t*>(dstBuffer) + res, [this](auto& val) {
		val = m_deCryptTable[val];
	});

	return res;
}
