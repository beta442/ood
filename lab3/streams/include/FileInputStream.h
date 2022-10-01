#ifndef FILEINPUTSTREAM_H
#define FILEINPUTSTREAM_H

#include <fstream>

#include "IInputDataStream.h"

class FileInputStream : public IInputDataStream
{
public:
	explicit FileInputStream(const char* fileName);
	explicit FileInputStream(const std::string& fileName);
	~FileInputStream();
	
	FileInputStream(const FileInputStream&) = delete;
	FileInputStream(FileInputStream&&) = delete;

	bool IsEOF() const override;
	uint8_t ReadByte() override;
	std::streamsize ReadBlock(void* dstBuffer, std::streamsize size) override;

private:
	std::ifstream m_ifStream;
};

#endif // !FILEINPUTSTREAM_H
