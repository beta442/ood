#ifndef TRY_OPEN_FILE_HPP
#define TRY_OPEN_FILE_HPP

#include <fstream>

template <typename StreamT, typename FileNameT>
void TryOpenFile(StreamT& stream, FileNameT&& fileName)
{
	stream.open(fileName);
	if (!stream.is_open())
	{
		throw std::ios_base::failure("Failed to open '" + std::string(std::forward<FileNameT>(fileName)) + "' file");
	}
}

#endif // !TRY_OPEN_FILE_HPP
