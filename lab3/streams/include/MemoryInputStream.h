#ifndef MEMORYINPUTSTREAM_H
#define MEMORYINPUTSTREAM_H

#include "IInputDataStream.h"

class MemoryInputStream : public IInputDataStream
{
public:
	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;
};

#endif // !MEMORYINPUTSTREAM_H
