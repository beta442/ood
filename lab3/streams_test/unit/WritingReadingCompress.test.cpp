#include "../include/pch.h"

#include "../../streams/include/CreateFileHandler.h"

constexpr auto TEST_FILE_NAME = "test.txt";

BOOST_AUTO_TEST_SUITE(WritingReadingCompress)

	BOOST_AUTO_TEST_CASE(Write_10_bytes_read_compressed_test)
	{
		const auto BLOCK_SIZE = 10;
		const auto EXPECTED_BLOCK_SIZE = 2;
		const char excpected[EXPECTED_BLOCK_SIZE]{ 10, 49 };
		const char* block = "1111111111";
		{
			auto oHandler = CreateOutputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), true);

			oHandler->WriteBlock(block, BLOCK_SIZE);
		}
		auto iHandler = CreateInputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), false);

		char chars[BLOCK_SIZE]{};

		iHandler->ReadBlock(chars, BLOCK_SIZE);
		BOOST_CHECK(std::equal(chars, chars + EXPECTED_BLOCK_SIZE, excpected));
	}

	BOOST_AUTO_TEST_CASE(Write_3_non_repeated_bytes_read_compressed_test)
	{
		const auto BLOCK_SIZE = 3;
		const char excpected[]{ 1, 49, 1,  50, 1, 51 };
		const char* block = "123";
		{
			auto oHandler = CreateOutputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), true);

			oHandler->WriteBlock(block, BLOCK_SIZE);
		}
		auto iHandler = CreateInputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), false);

		char chars[BLOCK_SIZE]{};

		iHandler->ReadBlock(chars, BLOCK_SIZE);
		BOOST_CHECK(std::equal(chars, chars + BLOCK_SIZE, excpected));
	}

	BOOST_AUTO_TEST_CASE(Write_10_compressed_read_decompressed_test)
	{
		const auto BLOCK_SIZE = 10;
		const char* excpected = "1234567890";
		const char* block = "1234567890";
		{
			auto oHandler = CreateOutputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), true);

			oHandler->WriteBlock(block, BLOCK_SIZE);
		}
		auto iHandler = CreateInputFileHandler(TEST_FILE_NAME, std::move(std::vector<unsigned char>{}), true);

		char chars[BLOCK_SIZE]{};

		iHandler->ReadBlock(chars, BLOCK_SIZE);
		BOOST_CHECK(std::equal(chars, chars + BLOCK_SIZE, excpected));
	}

BOOST_AUTO_TEST_SUITE_END();
