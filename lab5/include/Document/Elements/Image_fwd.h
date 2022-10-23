#ifndef COMMAND_DOCUMENT_ELEMENTS_IMAGE_IIMAGE_FWD_H_
#define COMMAND_DOCUMENT_ELEMENTS_IMAGE_IIMAGE_FWD_H_

#include <memory>

class IImage;

using IImageRawPtr = IImage*;

using IImagePtr = std::unique_ptr<IImage>;
using IImagePtrConst = std::unique_ptr<const IImage>;
using IImageSharedPtr = std::shared_ptr<IImage>;
using IImageSharedPtrConst = std::shared_ptr<const IImage>;

#endif // !COMMAND_DOCUMENT_ELEMENTS_IMAGE_IIMAGE_FWD_H_
