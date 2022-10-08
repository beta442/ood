#ifndef INPUT_STREAM_BASE_H
#define INPUT_STREAM_BASE_H

#include "IInputDataStream.h"

class InputStreamBase : public IInputDataStream
{
public:
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) final;

protected:
	InputStreamBase() = default;

	virtual uint8_t DerivedReadByte() = 0;
	virtual std::streamsize DerivedReadBlock(void* dstBuffer, std::streamsize size) = 0;
};

#endif // !INPUT_STREAM_BASE_H
