#ifndef MEMORYOUTPUTSTREAM_H
#define MEMORYOUTPUTSTREAM_H

#include "IOutputDataStream.h"

class MemoryOutputStream : public IOutputDataStream
{
public:
	void WriteByte(uint8_t data);
	void WriteBlock(const void* srcData, std::streamsize size);
};

#endif // !MEMORYOUTPUTSTREAM_H
