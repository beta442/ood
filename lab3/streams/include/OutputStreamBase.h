#ifndef OUTPUT_STREAM_BASE_H
#define OUTPUT_STREAM_BASE_H

#include "IOutputDataStream.h"

class OutputStreamBase : public IOutputDataStream
{
public:
	void WriteBlock(const void* srcData, std::streamsize size) final;

protected:
	OutputStreamBase() = default;

	virtual void DerivedWriteBlock(const void* srcData, std::streamsize size) = 0;
};

#endif // !OUTPUT_STREAM_BASE_H
