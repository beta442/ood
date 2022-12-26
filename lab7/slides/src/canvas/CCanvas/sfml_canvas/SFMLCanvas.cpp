#include "pch.h"

#include "SFMLCanvas.h"

namespace canvas
{

SFMLCanvas::SFMLCanvas(const RenderTarget& sfmlRenderTarger)
	: m_sfmlWindow(sfmlRenderTarger)
	, m_fillColor()
	, m_lineColor()
{
}

void SFMLCanvas::SetFillColor(const Style& color)
{
	if (color.IsEnabled().has_value() && color.IsEnabled().value() && color.GetColor().has_value())
	{
		m_fillColor = color.GetColor().value();
	}
}

void SFMLCanvas::SetLineColor(const Style& color)
{
	if (color.IsEnabled().has_value() && color.IsEnabled().value() && color.GetColor().has_value())
	{
		m_lineColor = color.GetColor().value();
	}
}

constexpr auto THICKNESS = 4;
constexpr auto CIRCLE_SHAPE_POINT_COUNT = 90;

void SFMLCanvas::DrawEllipse(double xLeftTop, double yLeftTop, double width, double height)
{
	auto ellipse = sf::CircleShape(static_cast<float>(width) / 2, CIRCLE_SHAPE_POINT_COUNT);

	ellipse.setPosition(static_cast<float>(xLeftTop), static_cast<float>(yLeftTop));
	ellipse.setScale(1, static_cast<float>(height / width));

	ellipse.setOutlineThickness(THICKNESS);
	ellipse.setOutlineColor(std::move(
		sf::Color(m_lineColor)));
	ellipse.setFillColor(std::move(
		sf::Color(m_fillColor)));

	m_sfmlWindow->draw(ellipse);
}

void SFMLCanvas::DrawTriangle(const PointD& p1, const PointD& p2, const PointD& p3)
{
	auto triangle = sf::ConvexShape{};

	triangle.setPointCount(3);
	triangle.setPoint(0, std::move(sf::Vector2f{ static_cast<float>(p1.x), static_cast<float>(p1.y) }));
	triangle.setPoint(1, std::move(sf::Vector2f{ static_cast<float>(p2.x), static_cast<float>(p2.y) }));
	triangle.setPoint(2, std::move(sf::Vector2f{ static_cast<float>(p3.x), static_cast<float>(p3.y) }));

	triangle.setOutlineThickness(THICKNESS);
	triangle.setOutlineColor(std::move(
		sf::Color(m_lineColor)));
	triangle.setFillColor(std::move(
		sf::Color(m_fillColor)));

	m_sfmlWindow->draw(triangle);
}

void SFMLCanvas::DrawRectangle(double xLeftTop, double yLeftTop, double width, double height)
{
	auto rect = sf::RectangleShape(std::move(
		sf::Vector2f(static_cast<float>(width), static_cast<float>(height))));

	rect.setPosition(std::move(
		sf::Vector2f(static_cast<float>(xLeftTop), static_cast<float>(yLeftTop))));
	rect.setOutlineThickness(THICKNESS);
	rect.setOutlineColor(std::move(
		sf::Color(m_lineColor)));
	rect.setFillColor(std::move(
		sf::Color(m_fillColor)));

	m_sfmlWindow->draw(rect);
}

} // namespace canvas
