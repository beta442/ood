#include "pch.h"

#include "ModernGraphicsRendererAdapter.h"
#include "graphics_lib/ICanvas.h"

graphics_lib::ICanvasPtr CreateAdapter(std::stringstream& ss)
{
	return std::make_unique<app::ModernGraphicsRendererAdapter>(ss);
}

std::string CreateExpectedAdapterOutput(int fromX, int fromY, int toX, int toY)
{
	// clang-format off
	return std::string("<draw>\n") +
		"<line fromX=\"" + std::to_string(fromX) +
		"\" fromY=\"" + std::to_string(fromY) +
		"\" toX=\"" + std::to_string(toX) +
		"\" toY=\"" + std::to_string(toY) +
		"\" />\n" + "</draw>\n";
	// clang-format on
}

BOOST_AUTO_TEST_SUITE(Adapter_tests)

	BOOST_AUTO_TEST_CASE(MoveTo_test)
	{
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);

		adapter->MoveTo(0, 10);

		BOOST_CHECK_EQUAL(ss.str(), "<draw>\n");
	}

	BOOST_AUTO_TEST_CASE(MoveTo_twice_throws)
	{
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);
		adapter->MoveTo(0, 10);

		BOOST_CHECK_THROW(adapter->MoveTo(0, 10), std::logic_error);
	}

	BOOST_AUTO_TEST_CASE(MoveTo_then_LineTo_test)
	{
		const int fromX = 0, fromY = 10, toX = 1000, toY = 10;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);
		adapter->MoveTo(fromX, fromY);

		adapter->LineTo(toX, toY);

		BOOST_CHECK_EQUAL(ss.str(), expectedCanvasOutput);
	}

	BOOST_AUTO_TEST_CASE(LineTo_doesnt_throw)
	{
		const int fromX = 0, fromY = 0, toX = 100, toY = 100;
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY);
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);

		adapter->LineTo(toX, toY);

		BOOST_CHECK_EQUAL(ss.str(), expectedCanvasOutput);
	}

BOOST_AUTO_TEST_SUITE_END()
