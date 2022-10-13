#ifndef DESIGNER_DESIGNER_H_
#define DESIGNER_DESIGNER_H_

#include "IDesigner.h"

class Designer : public IDesigner
{
public:
	PictureDraft CreateDraft(std::istream&) const final;
};

#endif // !DESIGNER_DESIGNER_H_
