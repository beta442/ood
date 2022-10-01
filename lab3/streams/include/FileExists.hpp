#ifndef FILE_EXISTS_HPP
#define FILE_EXISTS_HPP

#include <fstream>

template <typename FileType, typename FileNameT>
void FileExists(FileType& stream, FileNameT&& fileName)
{
	stream.open(fileName);
	if (!stream.is_open())
	{
		throw std::ios_base::failure("Failed to open '" + std::string(std::forward<FileNameT>(fileName)) + "' file");
	}
}

#endif // !FILE_EXISTS_HPP
