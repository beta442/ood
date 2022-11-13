#ifndef SLIDES_CANVAS_SFML_CANVAS_H_
#define SLIDES_CANVAS_SFML_CANVAS_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "ICanvas.h"

namespace canvas
{

class SFMLCanvas final : public ICanvas
{
public:
	using SFMLWindowSharedPtr = std::shared_ptr<sf::RenderWindow>;

	SFMLCanvas(const SFMLWindowSharedPtr& sfmlWindow);

	void SetLineColor(slides_common::RGBAColor color) override;
	void BeginFill(slides_common::RGBAColor color) override;
	void EndFill() override;
	void MoveTo(double x, double y) override;
	void LineTo(double x, double y) override;
	void DrawEllipse(double left, double top, double width, double height) override;

private:
	using SFMLWindowWeakPtr = std::weak_ptr<sf::RenderWindow>;

	SFMLWindowWeakPtr m_sfmlWindow;
};

} // namespace canvas

#endif // !SLIDES_CANVAS_SFML_CANVAS_H_
