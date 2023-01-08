#pragma once

#include "../BaseShape.h"

namespace drawable::shape
{

class Triangle : public BaseShape
{
public:
	using MyBase = BaseShape;

	explicit Triangle() = default;
	explicit Triangle(const PointD& p1, const PointD& p2, const PointD& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);
	explicit Triangle(PointD&& p1, PointD&& p2, PointD&& p3, IStylePtr&& outlineStyle, IStylePtr&& fillStyle);

	void SetFrame(const RectD& rect) override;

	void Draw(canvas::ICanvas& canvas) final;

private:
	PointD m_p1, m_p2, m_p3;
};

} // namespace drawable::shape
