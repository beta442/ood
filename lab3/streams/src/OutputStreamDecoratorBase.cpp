#include <ios>

#include "../include/OutputStreamDecoratorBase.h"

OutputStreamDecoratorBase::OutputStreamDecoratorBase(IOutputDataStreamPtr&& outputStreamPtr)
	: OutputStreamBase()
	, m_wrappedStream(std::move(outputStreamPtr))
{
}
