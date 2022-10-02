#ifndef ARGUMENTS_PARSER_H
#define ARGUMENTS_PARSER_H

#include "argparse.hpp"

constexpr auto DECRYPT_FLAG = "--decrypt";
constexpr auto ENCRYPT_FLAG = "--encrypt";

constexpr auto ÑOMPRESS_FLAG = "--compress";
constexpr auto DECOMPRESS_FLAG = "--decompress";

constexpr auto INPUT_FILE_PAR = "<input-file>";
constexpr auto OUTPUT_FILE_PAR = "<output-file>";

argparse::ArgumentParser ParseArgs(int argc, char* argv[]);

#endif // !ARGUMENTS_PARSER_H
