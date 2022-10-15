#ifndef DESIGNER_DESIGNER_H_
#define DESIGNER_DESIGNER_H_

#include "../Shapes/Factory/ShapeFactory.h"

#include "IDesigner.h"

class Designer : public IDesigner
{
public:
	template <typename FactoryPtr = IShapeFactorySharedPtr>
	Designer(FactoryPtr&& factoryPtr)
		: m_factoryPtr(std::forward<FactoryPtr>(factoryPtr))
	{
	}

	PictureDraft CreateDraft(std::istream& is) const final;

private:
	IShapeFactorySharedPtr m_factoryPtr;
};

#endif // !DESIGNER_DESIGNER_H_
