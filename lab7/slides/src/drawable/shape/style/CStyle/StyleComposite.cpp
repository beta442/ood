#include "pch.h"

#include "StyleComposite.h"

namespace drawable::shape
{

StyleComposite::StyleComposite(StyleEnumerator&& styleEnumerator, bool isEnabled)
	: m_styleEnumerator(std::move(styleEnumerator))
{
	MyBase::Enable(isEnabled);
}

using Callback = IEnumerator<IStyle>::Callback;

void StyleComposite::Enable(bool enable)
{
	Callback callback = [enable](auto& style) {
		style.Enable(enable);
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
	Callback callback = [color](auto& style) {
		style.SetColor(color);
	};
	m_styleEnumerator->EnumerateAll(callback);

	MyBase::SetColor(color);
}

} // namespace drawable::shape
