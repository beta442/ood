#include "../include/pch.h"

#include "app/ModernGraphicsRendererAdapter.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"

graphics_lib::ICanvasPtr CreateAdapter(std::stringstream& ss)
{
	modern_graphics_lib::ModernGraphicsRenderer renderer{ ss };
	graphics_lib::ICanvasPtr adapter = std::make_unique<app::ModernGraphicsRendererAdapter>(renderer);

	return adapter;
}

std::string XMLColorString(const modern_graphics_lib::RGBAColor& color)
{
	// clang-format off
	return "<color r=\"" + std::to_string(color.r) +
		"\" g=\"" + std::to_string(color.g) +
		"\" b=\"" + std::to_string(color.b) +
		"\" a=\"" + std::to_string(color.a) + "\" />";
	// clang-format on
}

std::string CreateExpectedAdapterOutput(int fromX, int fromY, int toX, int toY, const modern_graphics_lib::RGBAColor& color)
{
	// clang-format off
	return std::string("<draw>\n") +
		"<line fromX=\"" + std::to_string(fromX) +
		"\" fromY=\"" + std::to_string(fromY) +
		"\" toX=\"" + std::to_string(toX) +
		"\" toY=\"" + std::to_string(toY) +
		"\">\n" +
		"  " + XMLColorString(color) +
		"\n</line>\n" +
		"</draw>\n";
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
		const modern_graphics_lib::RGBAColor color{0, 0, 0, 1};
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY, color);
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);
		adapter->MoveTo(fromX, fromY);

		adapter->LineTo(toX, toY);

		BOOST_CHECK_EQUAL(ss.str(), expectedCanvasOutput);
	}

	BOOST_AUTO_TEST_CASE(LineTo_doesnt_throw)
	{
		const int fromX = 0, fromY = 0, toX = 100, toY = 100;
		const modern_graphics_lib::RGBAColor color{ 0, 0, 0, 1 };
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY, color);
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);

		adapter->LineTo(toX, toY);

		BOOST_CHECK_EQUAL(ss.str(), expectedCanvasOutput);
	}

	BOOST_AUTO_TEST_CASE(SetColor_tests)
	{
		const int fromX = 0, fromY = 0, toX = 100, toY = 100;
		const graphics_lib::Color color = 0xFF00FF;
		const modern_graphics_lib::RGBAColor rgbaColor{ 1, 0, 1, 1 };
		const std::string expectedCanvasOutput = CreateExpectedAdapterOutput(fromX, fromY, toX, toY, rgbaColor);
		std::stringstream ss{};
		auto adapter = CreateAdapter(ss);

		adapter->SetColor(color);
		adapter->MoveTo(fromX, fromY);
		adapter->LineTo(toX, toY);

		BOOST_CHECK_EQUAL(ss.str(), expectedCanvasOutput);
	}

BOOST_AUTO_TEST_SUITE_END()
