#include "pch.h"

#include "StyleComposite.h"

namespace slide
{

namespace shape
{

StyleComposite::StyleComposite(StyleEnumerator&& styleEnumerator, bool isEnabled)
	: m_styleEnumerator(std::move(styleEnumerator))
{
	MyBase::Enable(isEnabled);
}

using Callback = IEnumerator<IStyle>::Callback;

void slide::shape::StyleComposite::Enable(bool enable)
{
	Callback callback = [enable](const auto& style) {
		style->Enable(enable);
	};
	m_styleEnumerator->EnumerateAll(callback);

	MyBase::Enable(enable);
}

using CallbackConst = IEnumerator<IStyle>::CallbackConst;

StyleComposite::RGBAColorO StyleComposite::GetColor() const
{
	return MyBase::GetColor();
}

void StyleComposite::SetColor(RGBAColor color)
{
	Callback callback = [color](const auto& style) {
		style->SetColor(color);
	};
	m_styleEnumerator->EnumerateAll(callback);

	MyBase::SetColor(color);
}

} // namespace shape

} // namespace slide
