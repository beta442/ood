#ifndef TRY_OPEN_FILE_HPP
#define TRY_OPEN_FILE_HPP

#include <fstream>

template <typename StreamT, typename FileNameT>
void TryOpenFile(StreamT& stream, std::ios_base::openmode mode, FileNameT&& fileName)
{
	stream.open(fileName, mode);
	if (!stream.is_open())
	{
		throw std::ios_base::failure("Failed to open '" + std::string(std::forward<FileNameT>(fileName)) + "' file");
	}
}

#endif // !TRY_OPEN_FILE_HPP
