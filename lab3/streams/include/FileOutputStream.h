#ifndef FILEOUTPUTSTREAM_H
#define FILEOUTPUTSTREAM_H

#include <fstream>

#include "IOutputDataStream.h"

class FileOutputStream : public IOutputDataStream
{
public:
	explicit FileOutputStream(const char* fileName);
	explicit FileOutputStream(const std::string& fileName);
	~FileOutputStream();

	FileOutputStream(const FileOutputStream&) = delete;
	FileOutputStream(FileOutputStream&&) = delete;

	void WriteByte(uint8_t data);
	void WriteBlock(const void* srcData, std::streamsize size);

private:
	std::ofstream m_ofStream;
};

#endif // !FILEOUTPUTSTREAM_H
