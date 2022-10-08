#include "../include/pch.h"

#include "../../streams/include/CreateFileHandler.h"

constexpr auto TEST_FILE_NAME = "test.txt";

BOOST_AUTO_TEST_SUITE(WritingReadingCrpyt)

	BOOST_AUTO_TEST_CASE(Read_encrypted_and_write_decrypted_10_bytes_test)
	{
		const auto BLOCK_SIZE = 10;
		const char* block = "1234567890";
		{
			auto oHandler = CreateOutputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{ 0, 1, 2, 255 }), false);

			oHandler->WriteBlock(block, BLOCK_SIZE);
		}
		auto iHandler = CreateInputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{ 255, 2, 1, 0 }), false);
		char chars[BLOCK_SIZE]{};

		iHandler->ReadBlock(chars, BLOCK_SIZE);

		BOOST_CHECK(std::equal(block, block + BLOCK_SIZE, chars));
	}

BOOST_AUTO_TEST_SUITE_END();
