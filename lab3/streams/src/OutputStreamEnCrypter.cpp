#include "../include/CryptTableGenerator.hpp"
#include "../include/OutputStreamEnCrypter.h"

OutputStreamEnCrypter::OutputStreamEnCrypter(IOutputDataStreamPtr&& outputStreamPtr, unsigned char key)
	: OutputStreamDecoratorBase(std::move(outputStreamPtr))
	, m_enCryptTable(GenerateCryptTable(key))
{
}

void OutputStreamEnCrypter::WriteByte(uint8_t data)
{
	m_wrappee->WriteByte(m_enCryptTable[data]);
}

void OutputStreamEnCrypter::WriteBlock(const void* srcData, std::streamsize size)
{
}
