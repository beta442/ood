#ifndef OUTPUT_STREAM_DECORATOR_BASE_H
#define OUTPUT_STREAM_DECORATOR_BASE_H

#include "OutputStreamBase.h"

class OutputStreamDecoratorBase : public OutputStreamBase
{
protected:
	OutputStreamDecoratorBase(IOutputDataStreamPtr&& outputStreamPtr);

	IOutputDataStreamPtr m_wrappedStream;
};

#endif // !OUTPUT_STREAM_DECORATOR_BASE_H
