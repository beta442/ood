#pragma once

#include "enumarator/IEnumerator.h"

#include "../IStyle.h"

namespace slide
{

namespace shape
{

template <typename ContainerT>
class FillStyleEnumerator : public IEnumerator<IStyle>
{
public:
	using MyBase = IEnumerator<IStyle>;

	explicit FillStyleEnumerator(ContainerT& styleContainer)
		: m_items(styleContainer)
	{
	}

	void EnumerateAll(const Callback& callback) final
	{
		for (auto& item : m_items)
		{
			callback(TSharedPtr(&item->GetFillStyle()));
		}
	}

	void EnumerateAll(const CallbackConst& callback) const final
	{
		for (const auto& item : m_items)
		{
			callback(TSharedPtrConst(&item->GetFillStyle()));
		}
	}

private:
	ContainerT& m_items;
};

} // namespace shape

} // namespace slide
