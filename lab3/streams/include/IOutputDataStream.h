#ifndef IOUTPUTDATASTREAM_H
#define IOUTPUTDATASTREAM_H

#include <cstdint>
#include <string>

class IOutputDataStream
{
public:
	// all throws std::ios_base::failure
	virtual void WriteByte(uint8_t data) = 0; 
	virtual void WriteBlock(const void* srcData, std::streamsize size) = 0;

	virtual ~IOutputDataStream() = default;
};

#endif // !IOUTPUTDATASTREAM_H
