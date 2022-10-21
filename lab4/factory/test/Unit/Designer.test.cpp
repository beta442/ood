#include "../include/pch.h"

#include "../../include/Designer/Designer.h"

BOOST_AUTO_TEST_SUITE(Designer_tests)

	BOOST_AUTO_TEST_CASE(Designer_creates_draft)
	{
		std::istringstream iss{
			std::string("eLlIpsE black 145 40 38 21\n") +
			"\n" +
			"rectangle black 0 0 100 12\n" +
			"triangle black 140 140 365 144 143 400\n" +
			"regular-polygon grEEn 400 400 100 15\n"
		};
		const Point expectedEllipseP{ 145, 40 }, expectedRegularPolyP{400, 400};

		Designer d{std::move(std::make_shared<ShapeFactory>())};
		auto draft = d.CreateDraft(iss);

		BOOST_CHECK(draft.GetShapeCount() == 4);
		BOOST_CHECK(draft.GetShape(0)->GetBasePoint() == expectedEllipseP);
		BOOST_CHECK(draft.GetShape(0)->GetColor() == Color::BLACK);

		BOOST_CHECK(draft.GetShape(3)->GetBasePoint() == expectedRegularPolyP);
		BOOST_CHECK(draft.GetShape(3)->GetColor() == Color::GREEN);
	}

BOOST_AUTO_TEST_SUITE_END();
