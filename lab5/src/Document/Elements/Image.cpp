#include "../../../include/pch.h"

#include "../../../include/Document/Elements/Image.h"
#include "../../../include/Document/common.h"

constexpr auto TEMP_FILE_NAME_SIZE = 10;

constexpr std::array<std::string_view, 3> HTML_IMAGES_EXTENSIONS{
	".jpg",
	".gif",
	".png"
};

const std::string MIN_DIMENSION_SIZE_STR = std::to_string(MIN_DIMENSION_SIZE);
const std::string MAX_DIMENSION_SIZE_STR = std::to_string(MAX_DIMENSION_SIZE);

const std::string WIDTH_OUT_OF_RANGE_DIMENSION_ERR_MSG = "Given width is out of ranges. Min-Max: " + MIN_DIMENSION_SIZE_STR + "-" + MAX_DIMENSION_SIZE_STR;
const std::string HEIGHT_OUT_OF_RANGE_DIMENSION_ERR_MSG = "Given height is out of ranges. Min-Max: " + MIN_DIMENSION_SIZE_STR + "-" + MAX_DIMENSION_SIZE_STR;

void TryCheckIsImage(const StdPath& path)
{
	using namespace document_elements_common;

	try
	{
		bool isImage = IsImageExtention(HTML_IMAGES_EXTENSIONS, path.extension().generic_string());
		if (!std::filesystem::is_regular_file(path) || !isImage)
		{
			throw std::invalid_argument("Given path doesn't represent a file. Check if file exists and its extension. Given path: " + path.generic_string());
		}
	}
	catch (std::invalid_argument&)
	{
		throw;
	}
	catch (...)
	{
		throw std::domain_error("Failed to check given image path");
	}
}

template <typename BoundsT>
void TryCheckAreDimensionsInBounds(size_t width, size_t height, const BoundsT& lowerBound, const BoundsT& upperBound)
{
	if (!IsInBounds(lowerBound, upperBound, width))
	{
		throw std::invalid_argument(WIDTH_OUT_OF_RANGE_DIMENSION_ERR_MSG);
	}
	if (!IsInBounds(lowerBound, upperBound, height))
	{
		throw std::invalid_argument(HEIGHT_OUT_OF_RANGE_DIMENSION_ERR_MSG);
	}
}

StdPath TryCopyImage(const StdPath& from, const std::optional<StdPath>& to, const std::string& fileName)
{
	try
	{
		auto imagesPath = (to.has_value()) ? *to : CreateImagesDir();

		auto imagePath = (imagesPath / fileName);
		imagePath.replace_extension(from.extension());

		std::filesystem::copy(from, imagePath);

		return imagePath;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw std::domain_error("Failed to create images working dir or copy image");
	}
}

Image::Image(const StdPath& path, size_t width, size_t height)
	: m_path(path)
	, m_name(path.has_filename() ? path.filename().generic_string() : "")
	, m_width(width)
	, m_height(height)
{
	TryCheckIsImage(path);

	TryCheckAreDimensionsInBounds(width, height, MIN_DIMENSION_SIZE, MAX_DIMENSION_SIZE);

	m_path = TryCopyImage(m_path, std::optional<StdPath>(), MakeRandomFileName(TEMP_FILE_NAME_SIZE, 'a', 'z'));
}

Image::~Image()
{
	try
	{
		std::filesystem::remove(m_path);
	}
	catch (...)
	{
	}
}

const StdPath& Image::GetPath() const
{
	return m_path;
}

const std::string& Image::GetName() const
{
	return m_name;
}

size_t Image::GetWidth() const
{
	return m_width;
}

size_t Image::GetHeight() const
{
	return m_height;
}

void Image::Resize(size_t width, size_t height)
{
	m_width = width;
	m_height = height;
}

void Image::Save(const StdPath& path) const
{
	auto newPath = TryCopyImage(m_path, path, m_name);
	std::filesystem::remove(m_path);
	m_path = newPath;
}
