#include "include/pch.h"

#include "include/ArgumentsParser.h"
#include "include/CreateFileHandler.h"

int main(int argc, char* argv[])
{
	auto program = ParseArgs(argc, argv);

	try
	{
		auto inputFileHandler = CreateInputFileHandler(program.get(INPUT_FILE_PAR), program.get<std::vector<unsigned char>>(DECRYPT_FLAG));
		auto outputFileHandler = CreateOutputFileHandler(program.get(OUTPUT_FILE_PAR), program.get<std::vector<unsigned char>>(ENCRYPT_FLAG));

		while (true)
		{
			auto byte = inputFileHandler->ReadByte();
			if (inputFileHandler->IsEOF())
			{
				break;
			}
			outputFileHandler->WriteByte(byte);
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::exit(1);
	}

	return 0;
}
