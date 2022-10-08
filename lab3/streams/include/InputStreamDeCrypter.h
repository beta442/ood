#ifndef INPUT_STREAM_DE_CRYPTER_H
#define INPUT_STREAM_DE_CRYPTER_H

#include <vector>

#include "InputStreamDecoratorBase.h"

class InputStreamDeCrypter : public InputStreamDecoratorBase
{
public:
	InputStreamDeCrypter(IInputDataStreamPtr&& inputStreamPtr, unsigned char key);

private:
	uint8_t DerivedReadByte() final;
	std::streamsize DerivedReadBlock(void* dstBuffer, std::streamsize size) final;

	std::vector<uint8_t> m_deCryptTable;
};

#endif // !INPUT_STREAM_DE_CRYPTER_H
