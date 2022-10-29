#ifndef COMMAND_DOCUMENT_ELEMENTS_COMMON_H_
#define COMMAND_DOCUMENT_ELEMENTS_COMMON_H_

#include <algorithm>
#include <filesystem>

#include "../utility.hpp"

inline namespace document_elements_common
{

using StdPath = std::filesystem::path;

constexpr auto IMAGES_SAVE_DIR_NAME = "images";

const auto IMAGES_PATH = std::filesystem::current_path() / IMAGES_SAVE_DIR_NAME;

inline StdPath CreateImagesDir()
{
	if (!std::filesystem::exists(IMAGES_PATH))
	{
		std::filesystem::create_directory(IMAGES_PATH);
	}

	return IMAGES_PATH;
}

template <typename ExtensionsContainerT, typename StringT>
inline bool IsImageExtention(const ExtensionsContainerT& extensions, const StringT& extension)
{
	return std::any_of(extensions.begin(), extensions.end(), [&extension](const auto& el) noexcept {
		return IEqualStrings(extension, el);
	});
}

}; // namespace document_elements_common

#endif // !COMMAND_DOCUMENT_ELEMENTS_COMMON_H_
