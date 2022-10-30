#include <algorithm>

#include "../include/CryptTableGenerator.hpp"
#include "../include/InputStreamDeCrypter.h"

InputStreamDeCrypter::InputStreamDeCrypter(IInputDataStreamPtr&& inputStreamPtr, unsigned char key)
	: InputStreamDecoratorBase(std::move(inputStreamPtr))
	, m_deCryptTable(std::move(GenerateCryptTable<CryptMode::DECRYPT>(key)))
{
}

uint8_t InputStreamDeCrypter::DerivedReadByte()
{
	auto byte = m_wrappedStream->ReadByte();

	return m_deCryptTable[byte];
}

std::streamsize InputStreamDeCrypter::DerivedReadBlock(void* dstBuffer, std::streamsize size)
{
	auto res = m_wrappedStream->ReadBlock(dstBuffer, size);

	std::for_each(static_cast<unsigned char*>(dstBuffer), static_cast<unsigned char*>(dstBuffer) + res, [this](auto& val) {
		val = m_deCryptTable[val];
	});

	return res;
}
