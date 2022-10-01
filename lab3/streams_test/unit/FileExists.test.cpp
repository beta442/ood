#include "../include/pch.h"

#include "../../streams/include/FileExists.hpp"

BOOST_AUTO_TEST_SUITE(FileExistsTests)

	BOOST_AUTO_TEST_CASE(No_such_file_test)
	{
		std::ifstream iS{};
		BOOST_CHECK_THROW(FileExists(iS, "some_file_that_doesnt_exists.trash.brash.sash"), std::ios_base::failure);
	}

BOOST_AUTO_TEST_SUITE_END();
