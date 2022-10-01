#ifndef FILE_EXISTS_HPP
#define FILE_EXISTS_HPP

#include <fstream>

constexpr auto DEFAULT_IF_STREAM_OPEN_MODE = std::ios_base::in;
constexpr auto DEFAULT_OF_STREAM_OPEN_MODE = std::ios_base::out;

template <typename FileType, typename FileNameT>
void FileExists(FileType& stream, FileNameT&& fileName)
{
	std::ios_base::openmode mode;
	if constexpr (std::is_same<FileType, std::ifstream>::value)
	{
		mode = DEFAULT_IF_STREAM_OPEN_MODE;
	}
	if constexpr (std::is_same<FileType, std::ofstream>::value)
	{
		mode = DEFAULT_OF_STREAM_OPEN_MODE;
	}

	stream.open(fileName, mode);
	if (!stream.is_open())
	{
		throw std::ios_base::failure("Failed to open '" + std::string(std::forward<FileNameT>(fileName)) + "' file");
	}
}

#endif // !FILE_EXISTS_HPP
