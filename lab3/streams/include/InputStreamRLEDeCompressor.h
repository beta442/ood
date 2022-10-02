#ifndef INPUT_STREAM_RLE_DE_COMPRESSOR_H
#define INPUT_STREAM_RLE_DE_COMPRESSOR_H

#include "ByteSequenceInfo.hpp"
#include "InputStreamDecoratorBase.h"

class InputStreamRLEDeCompressor : public InputStreamDecoratorBase
{
public:
	InputStreamRLEDeCompressor(IInputDataStreamPtr&& inputStreamPtr);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	ByteSequenceInfo m_byteSequenceInfo;
};

#endif // !INPUT_STREAM_RLE_DE_COMPRESSOR_H
