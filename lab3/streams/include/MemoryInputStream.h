#ifndef MEMORYINPUTSTREAM_H
#define MEMORYINPUTSTREAM_H

#include "IInputDataStream.h"

#include <vector>

class MemoryInputStream : public IInputDataStream
{
public:
	explicit MemoryInputStream(const std::vector<uint8_t>& source);

	MemoryInputStream(const MemoryInputStream&) = delete;
	MemoryInputStream(MemoryInputStream&&) = delete;

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::streamoff m_offset;
	std::vector<uint8_t> m_iMemoryStream;
};

#endif // !MEMORYINPUTSTREAM_H
