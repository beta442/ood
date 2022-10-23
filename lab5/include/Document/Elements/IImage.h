#ifndef COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_
#define COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_

#include "../common.h"
#include "IElement.h"
#include "Image_fwd.h"

class IImage : public IElement
{
public:
	virtual StdPath GetPath() const = 0;

	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Resize(size_t width, size_t height) = 0;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_IIMAGE_H_
