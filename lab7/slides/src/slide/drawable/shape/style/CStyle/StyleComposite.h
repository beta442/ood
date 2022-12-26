#pragma once

#include "Style.h"
#include "enumarator/IEnumerator.h"

namespace slide
{

namespace shape
{

class StyleComposite : public Style
{
public:
	using MyBase = Style;
	using StyleEnumerator = IEnumeratorPtr<IStyle>;

	explicit StyleComposite(StyleEnumerator&& styleEnumerator, bool isEnabled = true);

	void Enable(bool enable) override;

	RGBAColorO GetColor() const override;
	void SetColor(RGBAColor color) override;

private:
	StyleEnumerator m_styleEnumerator;
};

} // namespace shape

} // namespace slide
