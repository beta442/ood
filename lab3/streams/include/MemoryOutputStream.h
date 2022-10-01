#ifndef MEMORYOUTPUTSTREAM_H
#define MEMORYOUTPUTSTREAM_H

#include <vector>

#include "IOutputDataStream.h"

class MemoryOutputStream : public IOutputDataStream
{
public:
	MemoryOutputStream();

	MemoryOutputStream(const MemoryOutputStream&) = delete;
	MemoryOutputStream(MemoryOutputStream&&) = delete;

	void WriteByte(uint8_t data);
	void WriteBlock(const void* srcData, std::streamsize size);

private:
	std::vector<uint8_t> m_oMemoryStream;
};

#endif // !MEMORYOUTPUTSTREAM_H
