#include "../../include/Shapes/RegularPolygon.h"

const Point& RegularPolygon::GetCenter() const noexcept
{
	if (!m_center.has_value())
	{
		m_center = GetCenterPointFromPoints(m_points);
	}

	return *m_center;
}

double RegularPolygon::GetRadius() const noexcept
{
	if (!m_radius.has_value())
	{
		if (m_points.size() >= 2)
		{
			m_radius = m_points[0].Distance(m_points[1]);
		}
		else
		{
			m_radius = 0;
		}
	}

	return *m_radius;
}

void RegularPolygon::Draw(ICanvas* canvas) const
{
}
