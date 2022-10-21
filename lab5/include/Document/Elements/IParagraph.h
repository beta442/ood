#ifndef COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_
#define COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_

#include <string>

class IParagraph
{
public:
	virtual std::string GetText()const = 0;
	virtual void SetText(const std::string& text) = 0;

	virtual ~IParagraph() = default;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_
