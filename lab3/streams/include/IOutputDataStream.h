#ifndef IOUTPUTDATASTREAM_H
#define IOUTPUTDATASTREAM_H

#include <cstdint>
#include <memory>
#include <string>

class IOutputDataStream
{
public:
	virtual void WriteByte(uint8_t data) = 0;
	virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

	virtual ~IOutputDataStream() = default;
};

using IOutputDataStreamPtr = std::unique_ptr<IOutputDataStream>;

#endif // !IOUTPUTDATASTREAM_H
