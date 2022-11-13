#ifndef SLIDES_SLIDE_SLIDE_H_
#define SLIDES_SLIDE_SLIDE_H_

#include "ISlide.h"

namespace slide
{

class Slide : public ISlide
{
public:
	Slide() = default;
	Slide(double width, double height);

	double GetWidth() const override;
	double GetHeight() const override;

	IShapes& GetShapes() const override;

	RGBAColor GetBackgroundColor() const override;
	void SetBackgroundColor(RGBAColor color) override;

	void Draw(canvas::ICanvas& canvas) override;

private:
	double m_width, m_height;
};

} // namespace slide

#endif // !SLIDES_SLIDE_SLIDE_H_
