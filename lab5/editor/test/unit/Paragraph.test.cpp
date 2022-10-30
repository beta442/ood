#include "../include/pch.h"

#include "../../../editor/include/Document/Elements/Paragraph.h"

BOOST_AUTO_TEST_SUITE(Paragraph_tests)

	BOOST_AUTO_TEST_CASE(Create_paragraph_test_1)
	{
		const char* expectedText = "ExpectedText";
		const Paragraph p{ expectedText };

		BOOST_CHECK(p.GetText() == expectedText);
	}

	BOOST_AUTO_TEST_CASE(Create_paragraph_test_2)
	{
		const char* expectedText = "";
		const Paragraph p{ expectedText };

		BOOST_CHECK(p.GetText() == expectedText);
	}

	BOOST_AUTO_TEST_CASE(Change_paragraph_text_test)
	{
		const char* expectedText = "ExpectedText";
		Paragraph p{ "" };

		p.SetText(expectedText);

		BOOST_CHECK(p.GetText() == expectedText);
	}

BOOST_AUTO_TEST_SUITE_END()
