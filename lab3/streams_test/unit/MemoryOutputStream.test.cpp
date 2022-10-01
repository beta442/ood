#include "../include/pch.h"

#include "../../streams/include/MemoryOutputStream.h"

BOOST_AUTO_TEST_SUITE(MemoryOutputStreamTests)

	BOOST_AUTO_TEST_CASE(Write_into_memory_stream_tests)
	{
		MemoryOutputStream oS{};

		const auto SIZE = 20, SIZE_TWICE = SIZE * 2, SIZE_2 = SIZE / 2;
		auto src = new int8_t[SIZE]{
			65,
			66,
			67,
		};

		oS.WriteByte(50);
		oS.WriteBlock(src, SIZE_TWICE);
		oS.WriteBlock(src, SIZE_2);
		oS.WriteBlock(src, SIZE);

		delete[] src;
	}

BOOST_AUTO_TEST_SUITE_END();
