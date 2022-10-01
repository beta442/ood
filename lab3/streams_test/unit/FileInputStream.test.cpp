#include "../include/pch.h"

#include "../../streams/include/FileInputStream.h"

constexpr auto FILE_NAME_THAT_DOESNT_EXISTS = "some_file_that_doesnt_exists.trash.brash.sash";
constexpr auto EMPTY_FILE_NAME = "empty.txt";
constexpr auto FILE_WITH_CONTENT_NAME = "fileWithContent.txt";

BOOST_AUTO_TEST_SUITE(FileInputStreamTests)

	BOOST_AUTO_TEST_CASE(No_such_file_test)
	{
		BOOST_CHECK_THROW(FileInputStream{ FILE_NAME_THAT_DOESNT_EXISTS }, std::ios_base::failure);
		BOOST_CHECK_THROW(FileInputStream{ std::string(FILE_NAME_THAT_DOESNT_EXISTS) }, std::ios_base::failure);
	}

	BOOST_AUTO_TEST_CASE(Empty_file_isnt_in_EOF)
	{
		auto handler = FileInputStream{ EMPTY_FILE_NAME };
		BOOST_CHECK(!handler.IsEOF());
	}

	BOOST_AUTO_TEST_CASE(Empty_file_is_in_EOF_after_read)
	{
		auto handler = FileInputStream{ EMPTY_FILE_NAME };
		handler.ReadByte();

		BOOST_CHECK(handler.IsEOF());
	}

	BOOST_AUTO_TEST_CASE(Empty_file_read_twice_throws)
	{
		auto handler = FileInputStream{ EMPTY_FILE_NAME };
		handler.ReadByte();

		BOOST_CHECK_THROW(handler.ReadByte(), std::ios_base::failure);
	}

	BOOST_AUTO_TEST_CASE(m_ReadByte_test)
	{
		auto handler = FileInputStream{ FILE_WITH_CONTENT_NAME };
		char byte = handler.ReadByte();

		BOOST_CHECK(byte == '0');
	}

	BOOST_AUTO_TEST_CASE(m_ReadBlock_throws_if_nullptr_provided)
	{
		auto handler = FileInputStream{ FILE_WITH_CONTENT_NAME };
		char* null{};

		BOOST_CHECK_THROW(handler.ReadBlock(null, 1);, std::ios_base::failure);
	}

	BOOST_AUTO_TEST_CASE(m_ReadBlock_with_empty_file_returns_0)
	{
		auto handler = FileInputStream{ EMPTY_FILE_NAME };
		const auto READ_SIZE = 10000;
		char* chars[READ_SIZE]{};

		BOOST_CHECK(handler.ReadBlock(chars, READ_SIZE) == 0);
	}

	BOOST_AUTO_TEST_CASE(m_ReadBlock_with_file_with_content_returns_12)
	{
		auto handler = FileInputStream{ FILE_WITH_CONTENT_NAME };
		const auto READ_SIZE = 10000;
		char* chars[READ_SIZE]{};

		BOOST_CHECK(handler.ReadBlock(chars, READ_SIZE) == 12);
	}

	BOOST_AUTO_TEST_CASE(m_ReadBlock_with_file_with_content_returns_5)
	{
		auto handler = FileInputStream{ FILE_WITH_CONTENT_NAME };
		const auto READ_SIZE = 5;
		char* chars[READ_SIZE]{};

		BOOST_CHECK(handler.ReadBlock(chars, READ_SIZE) == 5);
	}

BOOST_AUTO_TEST_SUITE_END();
