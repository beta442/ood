#include "../../../include/Document/Elements/Paragraph.h"

const std::string& Paragraph::GetText() const noexcept
{
	return m_text;
}

void Paragraph::SetText(const std::string& text)
{
	m_text = text;
}
