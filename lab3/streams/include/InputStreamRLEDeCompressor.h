#ifndef INPUT_STREAM_RLE_DE_COMPRESSOR_H
#define INPUT_STREAM_RLE_DE_COMPRESSOR_H

#include "ByteSequenceInfo.hpp"
#include "InputStreamDecoratorBase.h"

class InputStreamRLEDeCompressor : public InputStreamDecoratorBase
{
public:
	InputStreamRLEDeCompressor(IInputDataStreamPtr&& inputStreamPtr);


private:
	uint8_t DerivedReadByte() final;
	std::streamsize DerivedReadBlock(void* dstBuffer, std::streamsize size) final;

	ByteSequenceInfo m_byteSequenceInfo;
};

#endif // !INPUT_STREAM_RLE_DE_COMPRESSOR_H
