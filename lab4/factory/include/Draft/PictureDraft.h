#ifndef DRAFT_PICTURE_DRAFT_H_
#define DRAFT_PICTURE_DRAFT_H_

#include <memory>
#include <stdexcept>
#include <deque>

#include "../Shapes/IShape.h"

class PictureDraft
{
public:
	PictureDraft() = default;

	template <typename ShapePtr>
	void AddShape(ShapePtr&& ptr)
	{
		m_shapes.emplace_back(std::forward<ShapePtr>(ptr));
	}

	size_t GetShapeCount() const;
	const ShapeSharedPtr& GetShape(size_t index) const;

private:
	std::deque<ShapeSharedPtr> m_shapes;
};

#endif // !DRAFT_PICTURE_DRAFT_H_
