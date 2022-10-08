#ifndef FILEINPUTSTREAM_H
#define FILEINPUTSTREAM_H

#include <fstream>

#include "InputStreamBase.h"

class FileInputStream : public InputStreamBase
{
public:
	explicit FileInputStream(const char* fileName);
	explicit FileInputStream(const std::string& fileName);
	~FileInputStream();
	
	FileInputStream(const FileInputStream&) = delete;
	FileInputStream(FileInputStream&&) = delete;

	bool IsEOF() const final;

private:
	uint8_t DerivedReadByte() final;
	std::streamsize DerivedReadBlock(void* dstBuffer, std::streamsize size) final;

	std::ifstream m_ifStream;
};

#endif // !FILEINPUTSTREAM_H
