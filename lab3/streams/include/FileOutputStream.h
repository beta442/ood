#ifndef FILEOUTPUTSTREAM_H
#define FILEOUTPUTSTREAM_H

#include "IOutputDataStream.h"

class FileOutputStream : public IOutputDataStream
{
public:
	void WriteByte(uint8_t data);
	void WriteBlock(const void* srcData, std::streamsize size);
};

#endif // !FILEOUTPUTSTREAM_H
