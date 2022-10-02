#include "../include/InputStreamDecoratorBase.h"

InputStreamDecoratorBase::InputStreamDecoratorBase(IInputDataStreamPtr&& inputStreamPtr)
	: m_wrappedStream(std::move(inputStreamPtr))
{
}

bool InputStreamDecoratorBase::IsEOF() const
{
	return m_wrappedStream->IsEOF();
}
