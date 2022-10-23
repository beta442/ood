#ifndef COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_
#define COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_

#include <ostream>
#include <string>

#include "IElement.h"
#include "IParagraph_fwd.h"

class IParagraph : public IElement
{
public:
	virtual const std::string& GetText() const noexcept = 0;
	virtual void SetText(const std::string& text) = 0;
};

#endif // !COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_H_
