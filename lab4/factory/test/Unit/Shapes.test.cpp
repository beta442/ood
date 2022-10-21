#include "../include/pch.h"

#include "../../include/Shapes/Ellipse.h"
#include "../../include/Shapes/Rectangle.h"
#include "../../include/Shapes/RegularPolygon.h"
#include "../../include/Shapes/Triangle.h"

BOOST_AUTO_TEST_SUITE(Shapes_Unit_Test)

	BOOST_AUTO_TEST_CASE(Ellipse_tests)
	{
		const Point expectedP{ -100, 100 };
		const unsigned int expectedVerticalR = 0, expectedHorizontalR = 9999;
		const Color expectedC = Color::RED;
		
		Ellipse el{ expectedP, expectedVerticalR, expectedHorizontalR, expectedC };

		BOOST_CHECK(expectedP == el.GetBasePoint());
		BOOST_CHECK(expectedP == el.GetCenter());
		BOOST_CHECK_EQUAL(expectedVerticalR, el.GetVerticalRadius());
		BOOST_CHECK_EQUAL(expectedHorizontalR, el.GetHorizontalRadius());
		BOOST_CHECK(expectedC == el.GetColor());
	}

	BOOST_AUTO_TEST_CASE(Rectangle_tests)
	{
		const Point expectedLeftTopP{ -100, 100 };
		const unsigned int expectedWidth = 0, expectedHeight = 9999;
		const Point expectedRightBottomP{ static_cast<int>(expectedLeftTopP.x + expectedWidth), static_cast<int>(expectedLeftTopP.y + expectedHeight) };
		const Color expectedC = Color::RED;

		Rectangle rect{ expectedLeftTopP, expectedWidth, expectedHeight, expectedC };

		BOOST_CHECK(expectedLeftTopP == rect.GetBasePoint());
		BOOST_CHECK(expectedLeftTopP == rect.GetLeftTop());
		BOOST_CHECK(expectedRightBottomP == rect.GetRightBottom());
		BOOST_CHECK(expectedC == rect.GetColor());
	}

	BOOST_AUTO_TEST_CASE(Regular_polygon_tests)
	{
		const Point expectedBaseP{ -100, 100 };
		const unsigned int expectedRadius = 200;
		const size_t expectedVertexesCount = 300;
		const Color expectedColor = Color::BLACK;

		RegularPolygon regPoly{ expectedBaseP, expectedRadius, expectedVertexesCount, expectedColor };

		BOOST_CHECK(expectedBaseP == regPoly.GetBasePoint());
		BOOST_CHECK(expectedBaseP == regPoly.GetCenter());
		BOOST_CHECK(expectedColor == regPoly.GetColor());
		BOOST_CHECK(expectedRadius == regPoly.GetRadius());
		BOOST_CHECK(expectedVertexesCount == regPoly.GetVertexCount());
	}

	BOOST_AUTO_TEST_CASE(Triangle_tests)
	{
		const Point expectedVertex1{ -100, 100 }, expectedVertex2{ 300, 400 }, expectedVertex3{ 0, 0 };
		const Color expectedColor = Color::GREEN;

		Triangle t{ expectedVertex1, expectedVertex2, expectedVertex3, expectedColor };

		BOOST_CHECK(expectedVertex1 == t.GetBasePoint());
		BOOST_CHECK(expectedVertex1 == t.GetVertex1());
		BOOST_CHECK(expectedVertex2 == t.GetVertex2());
		BOOST_CHECK(expectedVertex3 == t.GetVertex3());
		BOOST_CHECK(expectedColor == t.GetColor());
	}

BOOST_AUTO_TEST_SUITE_END();
