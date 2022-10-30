#include "../include/pch.h"

#include "../../../editor/include/Menu/Menu.h"

BOOST_AUTO_TEST_SUITE(Menu_tests)

	BOOST_AUTO_TEST_CASE(Some)
	{
		const std::string firstCShortCut = "first", secondCShortCut = "second", thirdCShortCut = "third";
		const std::string exitC = "exit", exitCD = "Stops";
		const std::string firstDcsrp = "firstD", secondDscrp = "secondD", thirdD = "thirdD";
		std::istringstream is{ firstCShortCut + '\n' + secondCShortCut + '\n' + thirdCShortCut + '\n' + exitC + '\n' };
		std::ostringstream os{};
		Menu m{ is, os };
		bool firstExecuted = false, secondExecuted = false, thirdExecuted = false;
		m.AddItem(firstCShortCut, firstDcsrp, [&firstExecuted](std::istream&) noexcept {
			firstExecuted = true;
		});
		m.AddItem(secondCShortCut, secondDscrp, [&secondExecuted](std::istream&) noexcept {
			secondExecuted = true;
		});
		m.AddItem(thirdCShortCut, thirdD, [&thirdExecuted](std::istream&) noexcept {
			thirdExecuted = true;
		});
		m.AddItem(exitC, exitCD, [&m](std::istream&) noexcept {
			m.Exit();
		});
		const std::string expectedOut = std::string("Commands list:\n") + "--first: firstD\n" + "--second: secondD\n" + "--third: thirdD\n" + "--exit: Stops\n\n>>>>";

		m.Run();

		BOOST_CHECK(firstExecuted);
		BOOST_CHECK(secondExecuted);
		BOOST_CHECK(thirdExecuted);
		BOOST_CHECK(expectedOut == os.str());
	}

BOOST_AUTO_TEST_SUITE_END();
