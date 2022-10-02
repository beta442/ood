#include "../include/OutputStreamDecoratorBase.h"

OutputStreamDecoratorBase::OutputStreamDecoratorBase(IOutputDataStreamPtr&& outputStreamPtr)
	: m_wrappedStream(std::move(outputStreamPtr))
{
}
