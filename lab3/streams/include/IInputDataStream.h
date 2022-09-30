#ifndef IINPUTDATASTREAM_H
#define IINPUTDATASTREAM_H

#include <cstdint>
#include <string>

class IInputDataStream
{
public:
	// all throws std::ios_base::failuer
	virtual bool IsEOF() const = 0;
	virtual uint8_t ReadByte() = 0;
	virtual std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) = 0;

	virtual ~IInputDataStream() = default;
};

#endif // !IINPUTDATASTREAM_H
