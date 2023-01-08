#pragma once

#include "../IStyle.h"

namespace drawable::shape
{

class Style : public IStyle
{
public:
	Style() = default;
	Style(RGBAColor color);
	Style(RGBAColor color, bool enableOnInit);

	BoolO IsEnabled() const final;
	void Enable(bool enable) override;

	RGBAColorO GetColor() const override;
	void SetColor(RGBAColor color) override;

	bool operator==(const Style& other) const noexcept;

private:
	BoolO m_isEnabled;
	RGBAColorO m_color;
};

} // namespace drawable::shape
