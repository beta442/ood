#include "../include/pch.h"

#include "../../streams/include/MemoryInputStream.h"

BOOST_AUTO_TEST_SUITE(MemoryInputStreamTests)

	BOOST_AUTO_TEST_CASE(Attempt_to_read_from_empty_stream_sets_EOF)
	{
		MemoryInputStream mS({});

		mS.ReadByte();

		BOOST_CHECK(mS.IsEOF());
	}

	BOOST_AUTO_TEST_CASE(Attempt_to_read_after_EOF_throws)
	{
		MemoryInputStream mS({});

		mS.ReadByte();

		BOOST_CHECK_THROW(mS.ReadByte(), std::ios_base::failure);
	}

	BOOST_AUTO_TEST_CASE(Reading_per_byte_test)
	{
		const std::vector<uint8_t> initialV = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		MemoryInputStream mS(initialV);

		const std::vector<uint8_t> fromStreamV = std::invoke([&]() {
			std::vector<uint8_t> v;
			const auto size = initialV.size();
			v.reserve(size);

			for (size_t i = 0; i < size; ++i)
			{
				v.push_back(mS.ReadByte());
			}

			return v;
		});

		BOOST_CHECK(initialV == fromStreamV);
	}

	BOOST_AUTO_TEST_CASE(Reading_block_from_empty_stream)
	{
		MemoryInputStream mS({});
		const auto size = 1000;
		uint8_t* dest[size]{};

		BOOST_CHECK(mS.ReadBlock(dest, size) == 0);
		BOOST_CHECK(mS.IsEOF());
	}

	BOOST_AUTO_TEST_CASE(Reading_block_from_stream)
	{
		const std::vector<uint8_t> initialV = { 70, 71, 72, 73, 74, 75, 76, 77, 78 };
		MemoryInputStream mS(initialV);
		const auto size = 20, expectedSize = 9;
		uint8_t dest[size]{};

		BOOST_CHECK(mS.ReadBlock(dest, size) == expectedSize);
		std::for_each(initialV.begin(), initialV.end(), [&, counter = 0](auto& val) mutable noexcept {
			BOOST_CHECK(val == dest[counter++]);
		});
		BOOST_CHECK(mS.IsEOF());
	}

BOOST_AUTO_TEST_SUITE_END();
