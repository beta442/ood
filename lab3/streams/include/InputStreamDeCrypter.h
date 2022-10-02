#ifndef INPUT_STREAM_DE_CRYPTER_H
#define INPUT_STREAM_DE_CRYPTER_H

#include <vector>

#include "InputStreamDecoratorBase.h"

class InputStreamDeCrypter : public InputStreamDecoratorBase
{
public:
	InputStreamDeCrypter(IInputDataStreamPtr&& inputStreamPtr, unsigned char key);

	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::vector<uint8_t> m_deCryptTable;
};

#endif // !INPUT_STREAM_DE_CRYPTER_H
