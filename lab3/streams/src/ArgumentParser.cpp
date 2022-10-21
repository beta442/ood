#include "../include/ArgumentsParser.h"

argparse::ArgumentParser ParseArgs(int argc, char* argv[])
{
	argparse::ArgumentParser program("transform", "0.0.1");

	program.add_argument(ENCRYPT_FLAG)
		.help("encrypts <input-file>'s content into <output-file> with provided key. May be provided multiple times")
		.nargs(1)
		.default_value<std::vector<unsigned char>>({})
		.scan<'d', unsigned char>()
		.append();

	program.add_argument(DECRYPT_FLAG)
		.help("decrypts <input-file>'s content into <output-file> with provided key. May be provided multiple times")
		.nargs(1)
		.default_value<std::vector<unsigned char>>({})
		.scan<'d', unsigned char>()
		.append();

	program.add_argument(COMPRESS_FLAG)
		.help("compresses <input-file>'s content into <output-file>")
		.default_value(false)
		.implicit_value(true);

	program.add_argument(DECOMPRESS_FLAG)
		.help("decompresses <input-file>'s content into <output-file>")
		.default_value(false)
		.implicit_value(true);

	program.add_argument(INPUT_FILE_PAR)
		.help("source file to be transformed")
		.nargs(1)
		.required();

	program.add_argument(OUTPUT_FILE_PAR)
		.help("destination file")
		.nargs(1)
		.required();

	try
	{
		program.parse_args(argc, argv);
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		std::cerr << program;
		std::exit(1);
	}

	return program;
}
