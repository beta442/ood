#include "../../include/Draft/PictureDraft.h"

size_t PictureDraft::GetShapeCount() const
{
	return m_shapes.size();
}

const ShapeSharedPtr& PictureDraft::GetShape(size_t index) const
{
	if (index >= m_shapes.size())
	{
		throw std::out_of_range("Failed to find shape. Given index is out of range");
	}

	return m_shapes[index];
}
