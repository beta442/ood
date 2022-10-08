#ifndef FILEOUTPUTSTREAM_H
#define FILEOUTPUTSTREAM_H

#include <fstream>

#include "OutputStreamBase.h"

class FileOutputStream : public OutputStreamBase
{
public:
	explicit FileOutputStream(const char* fileName);
	explicit FileOutputStream(const std::string& fileName);
	~FileOutputStream();

	FileOutputStream(const FileOutputStream&) = delete;
	FileOutputStream(FileOutputStream&&) = delete;

	void WriteByte(uint8_t data) final;

private:
	void DerivedWriteBlock(const void* srcData, std::streamsize size) final;

	std::ofstream m_ofStream;
};

#endif // !FILEOUTPUTSTREAM_H
