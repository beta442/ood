#ifndef SLIDES_SLIDE_SHAPE_STYLE_H_
#define SLIDES_SLIDE_SHAPE_STYLE_H_

#include "IStyle.h"

namespace slide
{

namespace shape
{

class Style : public IStyle
{
public:
	BoolO IsEnabled() const override;
	void Enable(bool enable) override;

	RGBAColorO GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	BoolO m_isEnabled;
	RGBAColorO m_color;
};

} // namespace shape

} // namespace slide

#endif // !SLIDES_SLIDE_SHAPE_STYLE_H_
