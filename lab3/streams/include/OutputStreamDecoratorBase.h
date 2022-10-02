#ifndef OUTPUT_STREAM_DECORATOR_BASE_H
#define OUTPUT_STREAM_DECORATOR_BASE_H

#include "IOutputDataStream.h"

class OutputStreamDecoratorBase : public IOutputDataStream
{
protected:
	OutputStreamDecoratorBase(IOutputDataStreamPtr&& outputStreamPtr);

	IOutputDataStreamPtr m_wrappedStream;
};

#endif // !OUTPUT_STREAM_DECORATOR_BASE_H
