#ifndef INPUT_STREAM_DECORATOR_BASE_H
#define INPUT_STREAM_DECORATOR_BASE_H

#include <memory>

#include "IInputDataStream.h"

using IInputDataStreamPtr = std::unique_ptr<IInputDataStream>;

class InputStreamDecoratorBase : public IInputDataStream
{
public:
	bool IsEOF() const override;

protected:
	InputStreamDecoratorBase(IInputDataStreamPtr&& inputStreamPtr);

	IInputDataStreamPtr m_wrappee;
};

#endif // !INPUT_STREAM_DECORATOR_BASE_H
