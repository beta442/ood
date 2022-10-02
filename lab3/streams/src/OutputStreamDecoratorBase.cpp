#include "../include/OutputStreamDecoratorBase.h"

OutputStreamDecoratorBase::OutputStreamDecoratorBase(IOutputDataStreamPtr&& outputStreamPtr)
	: m_wrappee(std::move(outputStreamPtr))
{
}
