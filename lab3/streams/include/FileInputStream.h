#ifndef FILEINPUTSTREAM_H
#define FILEINPUTSTREAM_H

#include "IInputDataStream.h"

class FileInputStream : public IInputDataStream
{
public:
	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;
};

#endif // !FILEINPUTSTREAM_H
