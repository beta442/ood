#ifndef INPUT_STREAM_DECORATOR_BASE_H
#define INPUT_STREAM_DECORATOR_BASE_H

#include "InputStreamBase.h"

class InputStreamDecoratorBase : public InputStreamBase
{
public:
	bool IsEOF() const final;

protected:
	InputStreamDecoratorBase(IInputDataStreamPtr&& inputStreamPtr);

	IInputDataStreamPtr m_wrappedStream;
};

#endif // !INPUT_STREAM_DECORATOR_BASE_H
