#include "../include/pch.h"

#include "../../../editor/include/Document/HTMLDocument.h"

std::size_t CountFilesInDir(const std::filesystem::path& path)
{
	using std::filesystem::directory_iterator;
	return std::distance(directory_iterator(path), directory_iterator{});
}

BOOST_AUTO_TEST_SUITE(HTMLDocument_tests)

	BOOST_AUTO_TEST_CASE(Create_document_test_1)
	{
		const HTMLDocument doc{};

		BOOST_CHECK(doc.CanRedo() == false);
		BOOST_CHECK(doc.CanRedo() == false);
		BOOST_CHECK_THROW(doc.GetItem(0), std::out_of_range);
		BOOST_CHECK(doc.GetItemsCount() == 0);
		BOOST_CHECK(doc.GetTitle() == "Title");
		BOOST_CHECK(doc.begin()->HasNext() == false);
		BOOST_CHECK_THROW(doc.begin()->Next(), std::out_of_range);
		BOOST_CHECK_THROW(doc.begin()->Get(), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(Create_document_test_2)
	{
		const char* expectedName = "ExpectedName";
		const HTMLDocument doc{ expectedName };

		BOOST_CHECK(doc.GetTitle() == expectedName);
	}

	BOOST_AUTO_TEST_CASE(Change_document_title_test)
	{
		const char* expectedName = "Expected Name";
		HTMLDocument doc{};

		doc.SetTitle(expectedName);

		BOOST_CHECK(doc.GetTitle() == expectedName);
	}

	BOOST_AUTO_TEST_CASE(Document_undo_redo_tests)
	{
		const char* expectedName = "Expected Name";
		HTMLDocument doc{};
		doc.SetTitle(expectedName);

		BOOST_CHECK(doc.CanUndo() == true);
		BOOST_CHECK(doc.CanRedo() == false);

		doc.Undo();

		BOOST_CHECK(doc.GetTitle() == "Title");
		BOOST_CHECK(doc.CanUndo() == false);
		BOOST_CHECK(doc.CanRedo() == true);

		doc.Redo();

		BOOST_CHECK(doc.GetTitle() == expectedName);
		BOOST_CHECK(doc.CanUndo() == true);
		BOOST_CHECK(doc.CanRedo() == false);
	}

	BOOST_AUTO_TEST_CASE(Insert_paragraph_test)
	{
		HTMLDocument doc{};
		const char* expectedParagraphText = "Expected test";

		IParagraphSharedPtrConst p = doc.InsertParagraph(expectedParagraphText);

		BOOST_CHECK(p->GetText() == expectedParagraphText);
		BOOST_CHECK(doc.begin()->HasNext() == true);
		BOOST_CHECK(doc.begin()->Get().GetParagraph() != nullptr);
		BOOST_CHECK(doc.begin()->Get().GetImage() == nullptr);
		BOOST_CHECK(doc.CanRedo() == false);
		BOOST_CHECK(doc.CanUndo() == true);
		BOOST_CHECK(doc.GetItem(0).GetParagraph() == p);
		BOOST_CHECK(doc.GetItemsCount() == 1);
	}

	BOOST_AUTO_TEST_CASE(Replace_paragraph_test)
	{
		HTMLDocument doc{};
		const char* expectedParagraphText1 = "Expected test";
		const char* expectedParagraphText2 = "New text";
		IParagraphSharedPtrConst p1 = doc.InsertParagraph(expectedParagraphText1);

		IParagraphSharedPtrConst p2 = doc.ReplaceParagraph(expectedParagraphText2);

		BOOST_CHECK(p1->GetText() == expectedParagraphText1);
		BOOST_CHECK(p2->GetText() == expectedParagraphText2);
		BOOST_CHECK(doc.GetItemsCount() == 1);
		BOOST_CHECK(doc.GetItem(0).GetParagraph() == p2);
	}

	BOOST_AUTO_TEST_CASE(Insert_image_test)
	{
		const size_t expectedSize = 200;
		HTMLDocument doc{};

		IImageSharedPtrConst i = doc.InsertImage(IMG_JPG_SRC, expectedSize, expectedSize);

		BOOST_CHECK(i->GetHeight() == expectedSize);
		BOOST_CHECK(i->GetWidth() == expectedSize);
		BOOST_CHECK(i->GetName() == IMG_JPG_SRC);
		BOOST_CHECK(i->GetPath().parent_path() == IMAGES_PATH);
		BOOST_CHECK(doc.CanUndo() == true);
		BOOST_CHECK(doc.CanRedo() == false);
		BOOST_CHECK(doc.GetItemsCount() == 1);
		BOOST_CHECK(doc.GetItem(0).GetImage() == i);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Resize_image_test)
	{
		const size_t initSize = 200, expectedSize = 300;
		HTMLDocument doc{};
		IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, initSize, initSize);

		IImageSharedPtrConst i2 = doc.ResizeImage(expectedSize, expectedSize);

		BOOST_CHECK(i1->GetHeight() == initSize);
		BOOST_CHECK(i1->GetWidth() == initSize);
		BOOST_CHECK(i2->GetHeight() == expectedSize);
		BOOST_CHECK(i2->GetWidth() == expectedSize);
		BOOST_CHECK(doc.GetItemsCount() == 1);
		BOOST_CHECK(doc.GetItem(0).GetImage() == i2);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Save_document_test)
	{
		HTMLDocument doc{};
		IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		IImageSharedPtrConst i2 = doc.InsertImage(IMG_JPG_SRC, 300, 200);
		IParagraphSharedPtrConst p = doc.InsertParagraph("Some text");
		StdPath imgPath = IMAGES_PATH;
		StdPath saveDir = "test";

		doc.Save(saveDir);

		BOOST_CHECK(std::filesystem::exists(imgPath));
		BOOST_CHECK(std::filesystem::exists(saveDir));
		BOOST_CHECK(std::filesystem::exists(saveDir / IMAGES_PATH));
		BOOST_CHECK(CountFilesInDir(imgPath) == 2);
		BOOST_CHECK(CountFilesInDir(saveDir / IMAGES_PATH) == 2);

		std::filesystem::remove_all(saveDir);
		std::filesystem::remove_all(imgPath);
	}

	BOOST_AUTO_TEST_CASE(Save_document_when_working_images_deleted_from_temp_dir_throws)
	{
		HTMLDocument doc{};
		IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		IImageSharedPtrConst i2 = doc.InsertImage(IMG_JPG_SRC, 300, 200);
		StdPath imgPath = IMAGES_PATH;
		StdPath saveDir = "test";

		std::filesystem::remove_all(IMAGES_PATH);

		BOOST_CHECK_THROW(doc.Save(saveDir), std::exception);
		std::filesystem::remove_all(saveDir);
	}

	BOOST_AUTO_TEST_CASE(Delete_document_item_test)
	{
		HTMLDocument doc{};
		IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		IImageSharedPtrConst i2 = doc.InsertImage(IMG_JPG_SRC, 300, 200);

		doc.DeleteItem(0);

		BOOST_CHECK(doc.GetItemsCount() == 1);
		BOOST_CHECK(doc.GetItem(0).GetImage() == i2);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Replace_paragraph_throws)
	{
		HTMLDocument doc{};
		doc.InsertParagraph("Some text");
		doc.InsertImage(IMG_JPG_SRC, 200, 200);

		BOOST_CHECK_THROW(doc.ReplaceParagraph("new Text", 100), std::out_of_range);
		BOOST_CHECK_THROW(doc.ReplaceParagraph("new Text", 1), std::invalid_argument);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Resize_image_throws)
	{
		HTMLDocument doc{};
		doc.InsertImage(IMG_JPG_SRC, 200, 200);
		doc.InsertParagraph("Some text");
		const size_t expectedImageIndex = 0, paragraphIndex = 1, validSize = 200, invalidIndex = 100;

		BOOST_CHECK_THROW(doc.ResizeImage(validSize, validSize, invalidIndex), std::out_of_range);
		BOOST_CHECK_THROW(doc.ResizeImage(validSize, validSize, paragraphIndex), std::invalid_argument);
		BOOST_CHECK_THROW(doc.ResizeImage(0, 300, expectedImageIndex), std::invalid_argument);
		BOOST_CHECK_THROW(doc.ResizeImage(300, 0, expectedImageIndex), std::invalid_argument);
		BOOST_CHECK_THROW(doc.ResizeImage(1000000, 300, expectedImageIndex), std::invalid_argument);
		BOOST_CHECK_THROW(doc.ResizeImage(300, 1000000, expectedImageIndex), std::invalid_argument);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Undo_redo_deletes_undone_image_test)
	{
		HTMLDocument doc{};
		const IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		const IParagraphSharedPtrConst p1 = doc.InsertParagraph("Some text");
		doc.InsertParagraph("Some text");
		doc.InsertImage(IMG_JPG_SRC, 300, 300);
		doc.Undo();
		doc.InsertParagraph("Some text");

		BOOST_CHECK(CountFilesInDir(IMAGES_PATH) == 1);

		std::filesystem::remove_all(IMAGES_PATH);
	}

	BOOST_AUTO_TEST_CASE(Insert_command_test)
	{
		HTMLDocument doc{};
		const IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		const IParagraphSharedPtrConst p1 = doc.InsertParagraph("Some text");

		doc.Undo();
		doc.Redo();
		BOOST_CHECK(doc.GetItemsCount() == 2);
	}

	BOOST_AUTO_TEST_CASE(Delete_command_test)
	{
		HTMLDocument doc{};
		const IImageSharedPtrConst i1 = doc.InsertImage(IMG_JPG_SRC, 200, 200);
		const IParagraphSharedPtrConst p1 = doc.InsertParagraph("Some text");
		doc.DeleteItem(0);

		doc.Undo();
		doc.Redo();
		BOOST_CHECK(doc.GetItemsCount() == 1);
	}

BOOST_AUTO_TEST_SUITE_END();
