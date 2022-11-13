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

	double GetWidth() const;
	double GetHeight() const;

	IShapes& GetShapes() const;

	void Draw(const canvas::ICanvas& canvas);

private:
	double m_width, m_height;
};

} // namespace slide

#endif // !SLIDES_SLIDE_SLIDE_H_
