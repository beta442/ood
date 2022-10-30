#include "../include/CryptTableGenerator.hpp"
#include "../include/OutputStreamEnCrypter.h"

OutputStreamEnCrypter::OutputStreamEnCrypter(IOutputDataStreamPtr&& outputStreamPtr, unsigned char key)
	: OutputStreamDecoratorBase(std::move(outputStreamPtr))
	, m_enCryptTable(GenerateCryptTable(key))
{
}

void OutputStreamEnCrypter::WriteByte(uint8_t data)
{
	m_wrappedStream->WriteByte(m_enCryptTable[data]);
}

void OutputStreamEnCrypter::DerivedWriteBlock(const void* srcData, std::streamsize size)
{
	auto buffer = static_cast<const unsigned char*>(srcData);

	for (auto index = 0; index < size; ++index)
	{
		WriteByte(*(buffer++));
	}
}
