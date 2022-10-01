#include "../include/pch.h"

#include "../../streams/include/FileOutputStream.h"

constexpr auto READ_ONLY_FILE_NAME = "readonly.txt";
constexpr auto TEST_FILE_NAME = "test.txt";

BOOST_AUTO_TEST_SUITE(FileOutputStreamTests)

	BOOST_AUTO_TEST_CASE(Attempt_to_open_read_only_file_throws)
	{
		BOOST_CHECK_THROW(FileOutputStream{ READ_ONLY_FILE_NAME }, std::ios_base::failure);
		BOOST_CHECK_THROW(FileOutputStream{ std::string(READ_ONLY_FILE_NAME) }, std::ios_base::failure);
	}

	BOOST_AUTO_TEST_CASE(Write_one_byte_test)
	{
		auto handler = FileOutputStream{ TEST_FILE_NAME };
		handler.WriteByte('1');
	}

	BOOST_AUTO_TEST_CASE(Write_10_bytes_test)
	{
		auto handler = FileOutputStream{ TEST_FILE_NAME };
		const auto blockSize = 10;
		const auto blockSize_2 = 5;
		const auto blockSizeTwice = blockSize * 2;
		const char* block = "0123456789";

		handler.WriteBlock(block, blockSize);
		handler.WriteBlock(block, blockSize_2);
		handler.WriteBlock(block, blockSizeTwice);
	}

BOOST_AUTO_TEST_SUITE_END();
