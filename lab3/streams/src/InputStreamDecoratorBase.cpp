#include "../include/InputStreamDecoratorBase.h"

InputStreamDecoratorBase::InputStreamDecoratorBase(IInputDataStreamPtr&& inputStreamPtr)
	: m_wrappee(std::move(inputStreamPtr))
{
}

bool InputStreamDecoratorBase::IsEOF() const
{
	return m_wrappee->IsEOF();
}
