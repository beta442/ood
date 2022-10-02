#ifndef OUTPUT_STREAM_RLE_COMPRESSOR_H
#define OUTPUT_STREAM_RLE_COMPRESSOR_H

#include "ByteSequenceInfo.hpp"
#include "OutputStreamDecoratorBase.h"

class OutputStreamRLECompressor : public OutputStreamDecoratorBase
{
public:
	OutputStreamRLECompressor(IOutputDataStreamPtr&& outputStreamPtr);
	~OutputStreamRLECompressor();

	void WriteByte(uint8_t data) override;
	void WriteBlock(const void* srcData, std::streamsize size) override;

private:
	void Flush();

	ByteSequenceInfo m_byteSequenceInfo;
};

#endif // !OUTPUT_STREAM_RLE_COMPRESSOR_H
