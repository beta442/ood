#ifndef DESIGNER_IDESIGNER_H_
#define DESIGNER_IDESIGNER_H_

#include <sstream>

#include "../Draft/PictureDraft.h"

class IDesigner
{
public:
	virtual PictureDraft CreateDraft(std::istream& stream) const = 0;

	virtual ~IDesigner() = default;
};

#endif // !DESIGNER_IDESIGNER_H_
