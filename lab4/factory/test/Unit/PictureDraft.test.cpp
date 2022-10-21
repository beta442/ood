#include "../include/pch.h"

#include "../../include/Draft/PictureDraft.h"
#include "../../include/Shapes/Ellipse.h"

BOOST_AUTO_TEST_SUITE(Picture_draft_tests)

	BOOST_AUTO_TEST_CASE(Picture_draft_after_create)
	{
		PictureDraft draft{};
		
		BOOST_CHECK(draft.GetShapeCount() == 0);
		BOOST_CHECK_THROW(draft.GetShape(100), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(Picture_draft_add_shape)
	{
		const Point expectedPoint{ 0, 0 };
		const unsigned int expectedVR = 100, expectedHR = 300;
		const Color expectedColor = Color::RED;
		PictureDraft draft{};
		draft.AddShape(std::make_shared<Ellipse>(expectedPoint, expectedVR, expectedHR, expectedColor));

		const auto& shape = draft.GetShape(0);

		BOOST_CHECK(draft.GetShapeCount() == 1);
		BOOST_CHECK_THROW(draft.GetShape(1), std::out_of_range);
		BOOST_CHECK(shape->GetBasePoint() == expectedPoint);
		BOOST_CHECK(shape->GetColor() == expectedColor);
	}

	BOOST_AUTO_TEST_CASE(Picture_draft_add_shapes)
	{
		const size_t expectedShapesQuantity = 100;
		PictureDraft draft{};
		for (int i = 0; i < expectedShapesQuantity; ++i)
		{
			draft.AddShape(std::move(std::make_shared<Ellipse>(Point{ 0 - i, 0 + i }, 100 - i, 100 + i, Color::RED)));
		}

		BOOST_CHECK(draft.GetShapeCount() == expectedShapesQuantity);
		BOOST_CHECK_THROW(draft.GetShape(expectedShapesQuantity), std::out_of_range);
		BOOST_CHECK_NO_THROW(draft.GetShape(expectedShapesQuantity - 1));
	}

BOOST_AUTO_TEST_SUITE_END();
