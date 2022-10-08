#ifndef OUTPUT_STREAM_EN_CRYPTER_H
#define OUTPUT_STREAM_EN_CRYPTER_H

#include "OutputStreamDecoratorBase.h"

class OutputStreamEnCrypter : public OutputStreamDecoratorBase
{
public:
	OutputStreamEnCrypter(IOutputDataStreamPtr&& outputStreamPtr, unsigned char key);

	void WriteByte(uint8_t data) final;

private:
	void DerivedWriteBlock(const void* srcData, std::streamsize size) final;

	std::vector<uint8_t> m_enCryptTable;
};

#endif // !OUTPUT_STREAM_EN_CRYPTER_H
