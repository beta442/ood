#ifndef DRAFT_PICTURE_DRAFT_H_
#define DRAFT_PICTURE_DRAFT_H_

#include <deque>
#include <stdexcept>

#include "../Shapes/IShape.h"

class PictureDraft
{
public:
	template <typename ShapePtr>
	void AddShape(ShapePtr&& ptr)
	{
		m_shapes.emplace_back(std::forward<ShapePtr>(ptr));
	}

	const ShapeSharedPtr& GetShape(size_t index) const;
	size_t GetShapeCount() const;

	const auto begin() const
	{
		return m_shapes.begin();
	}

	const auto end() const
	{
		return m_shapes.end();
	}

private:
	std::deque<ShapeSharedPtr> m_shapes{};
};

#endif // !DRAFT_PICTURE_DRAFT_H_
