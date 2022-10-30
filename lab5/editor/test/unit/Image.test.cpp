#include "../include/pch.h"

#include "../../../editor/include/Document/Elements/Image.h"

BOOST_AUTO_TEST_SUITE(Image_tests)

	BOOST_AUTO_TEST_CASE(Create_image_test)
	{
		const size_t expectedWidth = 100, expectedHeight = 100;

		Image i{ IMG_JPG_SRC, expectedWidth, expectedHeight };

		BOOST_CHECK(i.GetHeight() == expectedHeight);
		BOOST_CHECK(i.GetWidth() == expectedWidth);
		BOOST_CHECK(i.GetName() == IMG_JPG_SRC);
		BOOST_CHECK(i.GetPath().parent_path() == IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Image_ctor_throws_test)
	{
		BOOST_CHECK_THROW(Image some("abracadabra", 100, 100), std::invalid_argument);
		BOOST_CHECK_THROW(Image some(IMG_PDF_NAME, 100, 100), std::invalid_argument);
		BOOST_CHECK_THROW(Image some(IMG_JPG_SRC, MIN_DIMENSION_SIZE - 1, 100), std::invalid_argument);
		BOOST_CHECK_THROW(Image some(IMG_JPG_SRC, 100, MIN_DIMENSION_SIZE - 1), std::invalid_argument);
		BOOST_CHECK_THROW(Image some(IMG_JPG_SRC, MAX_DIMENSION_SIZE + 1, 100), std::invalid_argument);
		BOOST_CHECK_THROW(Image some(IMG_JPG_SRC, 100, MAX_DIMENSION_SIZE + 1), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Change_image_size_test)
	{
		const size_t expectedWidth = 100, expectedHeight = 100, changeByValue = 50;
		Image i{ IMG_JPG_SRC, expectedWidth, expectedHeight };

		i.Resize(expectedWidth - changeByValue, expectedHeight + changeByValue);

		BOOST_CHECK(i.GetWidth() == expectedWidth - changeByValue);
		BOOST_CHECK(i.GetHeight() == expectedHeight + changeByValue);
	}

	BOOST_AUTO_TEST_CASE(Change_image_size_throws)
	{
		const size_t expectedWidth = 100, expectedHeight = 100, changeByValue = 50;
		Image i{ IMG_JPG_SRC, expectedWidth, expectedHeight };

		BOOST_CHECK_THROW(i.Resize(MIN_DIMENSION_SIZE - 1, 100), std::invalid_argument);
		BOOST_CHECK_THROW(i.Resize(100, MIN_DIMENSION_SIZE - 1), std::invalid_argument);
		BOOST_CHECK_THROW(i.Resize(MAX_DIMENSION_SIZE + 1, 100), std::invalid_argument);
		BOOST_CHECK_THROW(i.Resize(100, MAX_DIMENSION_SIZE + 1), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(Save_img_test)
	{
		const size_t expectedWidth = 100, expectedHeight = 100, changeByValue = 50;
		const Image i{ IMG_JPG_SRC, expectedWidth, expectedHeight };

		i.Save(IMAGES_PATH);

		BOOST_CHECK(i.GetPath() == (StdPath(IMAGES_PATH) /= IMG_JPG_SRC));
	}

BOOST_AUTO_TEST_SUITE_END();
