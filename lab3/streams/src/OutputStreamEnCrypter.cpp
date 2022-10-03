#include "../include/CryptTableGenerator.hpp"
#include "../include/OutputStreamEnCrypter.h"

#include <fstream>

OutputStreamEnCrypter::OutputStreamEnCrypter(IOutputDataStreamPtr&& outputStreamPtr, unsigned char key)
	: OutputStreamDecoratorBase(std::move(outputStreamPtr))
	, m_enCryptTable(GenerateCryptTable(key))
{
}

void OutputStreamEnCrypter::WriteByte(uint8_t data)
{
	m_wrappedStream->WriteByte(m_enCryptTable[data]);
}

constexpr auto WRITE_BLOCK_FAILURE_NULLPTR_MSG = "Failed write block attempt. nullptr in _1 parameter is provided";

void OutputStreamEnCrypter::WriteBlock(const void* srcData, std::streamsize size)
{
	if (srcData == nullptr)
	{
		throw std::ios_base::failure(WRITE_BLOCK_FAILURE_NULLPTR_MSG);
	}

	auto buffer = static_cast<const uint8_t*>(srcData);

	for (auto index = 0; index < size; ++index)
	{
		WriteByte(*(buffer++));
	}
}
